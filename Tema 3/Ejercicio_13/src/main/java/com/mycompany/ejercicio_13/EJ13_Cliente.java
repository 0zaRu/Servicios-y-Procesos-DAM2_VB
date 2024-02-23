package com.mycompany.ejercicio_13;

import java.io.DataOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author arube
 */
public class EJ13_Cliente {
    
    private static String nombreUsr;
    private static InetAddress SERVERIP;
    private static int PUERTO = 9876;
    
    public static void main(String[] args) {
        System.out.println("TERMINAL CLIENTE");
        
        Scanner kb = new Scanner(System.in);
        Socket cliente = null;
        DataOutputStream doSalida = null;
        ObjectInputStream doEntrada = null;
        
        try{
            SERVERIP = InetAddress.getByName("localhost");
            
            cliente = new Socket(SERVERIP, PUERTO);
            doEntrada = new ObjectInputStream(cliente.getInputStream());
            
            Informacion informacion = (Informacion) doEntrada.readObject();
            informacion.verTabla();
            
            System.out.print("Inserta el nombre de jugador: ");
            nombreUsr = kb.nextLine();
            
            ArrayList<String> respuestas = (ArrayList<String>) informacion.ejecutaPregunta();            
            
            int resptAcertadas = 0;
            for(int i = 0; i < informacion.getPreguntas().length; i++)
                if(informacion.getRespuestasValidas()[i].equals(respuestas.get(i)))
                    resptAcertadas++;
            
            System.out.print("\nRespuestas dadas: " + respuestas.size() + "\nRespuestas acertadas: "+ resptAcertadas);
            
            
            
            
            respuestas.add(nombreUsr);
            respuestas.add("Estan han sido todas las preguntas");
            
            doSalida = new DataOutputStream(cliente.getOutputStream());
            
            for (String respueta : respuestas)
                doSalida.writeUTF(respueta);
            
        } catch (Exception e){
            Logger.getLogger(EJ13_Cliente.class.getName()).log(Level.SEVERE, null, e);
        }
        finally{
            try {
                
                doSalida.close();
                doEntrada.close();
                kb.close();
                cliente.close();
                
            } catch (IOException ex) {
                Logger.getLogger(EJ13_Cliente.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
        
    
}
