package com.mycompany.ejercicio_13;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author arube
 */
public class EJ13_Servidor {
    
    private static Informacion informacion = new Informacion();
    
    private static ServerSocket socket;
    private static int PUERTO = 9876;
    
    public static void main(String[] args) {
        System.out.println("== TERMINAL SERVIDOR ==");

        try {
            socket = new ServerSocket(PUERTO);
            
            while (true) {
           
                Socket conexion = socket.accept();
                
                HServidor hilo = new HServidor(conexion, informacion);
                hilo.start();
                
            }
        } catch (IOException e) {
            Logger.getLogger(EJ13_Servidor.class.getName()).log(Level.SEVERE, null, e);
        }
        finally{
            try {
            
                socket.close();
            
            } catch (IOException ex) {
                Logger.getLogger(EJ13_Servidor.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}


/**
 *
 * @author arube
 */
class HServidor extends Thread {

    private Socket socketCliente;
    private Informacion informacion;
    
    public HServidor(Socket conexion, Informacion informacion) {
        this.socketCliente = conexion;
        this.informacion = informacion;
    }

    @Override
    public void run() {
        
        int puntuacion = 0;
        String respuesta = "";
        ObjectOutputStream doSalida = null;
        DataInputStream doEntrada = null;
        
        try{
            doSalida = new ObjectOutputStream(socketCliente.getOutputStream());
            doEntrada = new DataInputStream(socketCliente.getInputStream());
            doSalida.writeObject(informacion);

            ArrayList<String> respuestasConUsr = new ArrayList<>();
            
            while (!(respuesta = doEntrada.readUTF()).equals("Estan han sido todas las preguntas")) 
                respuestasConUsr.add(respuesta);
            
            for (int i = 0; i < respuestasConUsr.size()-1; i++)
                if (respuestasConUsr.get(i).equalsIgnoreCase(informacion.getRespuestasValidas()[i]))
                    puntuacion++;
                
            
            String nombre = respuestasConUsr.get(respuestasConUsr.size()-1);
            informacion.addPuntos(nombre, puntuacion);
            informacion.verTabla();
            
        } catch (Exception e){
            Logger.getLogger(HServidor.class.getName()).log(Level.SEVERE, null, e);
        }
        finally{
            try {
                
                doSalida.close();
                doEntrada.close();
                socketCliente.close();
            
            } catch (IOException ex) {
                Logger.getLogger(HServidor.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}