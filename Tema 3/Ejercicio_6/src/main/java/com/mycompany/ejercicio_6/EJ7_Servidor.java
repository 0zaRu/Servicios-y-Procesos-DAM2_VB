package com.mycompany.ejercicio_6;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author arube
 */
public class EJ7_Servidor {
        
    public static void main(String[] args) {
        System.out.println("TERMINAL SERVIDOR");
        int puerto = 9876;
        
        //0 para tipo de operación, 1 y 2 los valores a operar. 3 el resultado
        float[] operacion = new float[4];
        
        Socket socketCliente1 = null;
        DataOutputStream doSalida = null;
        DataInputStream diEntrada = null;
        
        try{
            ServerSocket serverSocket = new ServerSocket(puerto);
            socketCliente1 = serverSocket.accept();
            
            doSalida = new DataOutputStream(socketCliente1.getOutputStream());
            diEntrada = new DataInputStream(socketCliente1.getInputStream());
            
            while(true){    
                for(int i=0; i < operacion.length-1; i++){
                    operacion[i] = 0;
                    System.out.println("EL CLIENTE HA SELECCIONADO: "+ (operacion[i] = diEntrada.readFloat()));
                }

                switch((int)operacion[0]){
                    case 1: operacion[3] = operacion[1]+operacion[2]; break;
                    case 2: operacion[3] = operacion[1]-operacion[2]; break;
                    case 3: operacion[3] = operacion[1]*operacion[2]; break;
                    case 4: operacion[3] = operacion[1]/operacion[2]; break;
                }
                System.out.println(operacion[3]);
                
                doSalida.writeFloat(operacion[3]);
            }
            
        }catch(IOException e){
            System.err.println("Error a la hora de establecer conexiones");
        }
        finally{
            try {
                
                doSalida.close();
                diEntrada.close();
                socketCliente1.close();
            
            } catch (IOException ex) {
                Logger.getLogger(EJ7_Servidor.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}
