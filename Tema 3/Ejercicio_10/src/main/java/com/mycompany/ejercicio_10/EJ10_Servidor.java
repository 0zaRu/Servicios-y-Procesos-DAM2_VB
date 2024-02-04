package com.mycompany.ejercicio_10;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.util.Arrays;

/**
 *
 * @author arube
 */
public class EJ10_Servidor {
        
    public static void main(String[] args) {
        System.out.println("TERMINAL SERVIDOR");
        int puerto = 9876;
        
        //0 para tipo de operación, 1 y 2 los valores a operar. 3 el resultado
        float[] operacion = new float[4];
        byte[] buffer = new byte[1024];
        DatagramSocket socket = null;
        
        try{
            socket = new DatagramSocket(puerto);
            
            while(true){
                Arrays.fill(buffer, (byte)0);
                DatagramPacket datagrama = new DatagramPacket(buffer, buffer.length);
                
                System.out.println("A la espera de información ...");
                
                for(int i=0; i < operacion.length-1; i++){
                    socket.receive(datagrama);
                    String datos = new String(datagrama.getData());
                    System.out.println("Recibido: "+(operacion[i] = Float.parseFloat(datos)));
                }

                switch((int)operacion[0]){
                    case 1: operacion[3] = operacion[1]+operacion[2]; break;
                    case 2: operacion[3] = operacion[1]-operacion[2]; break;
                    case 3: operacion[3] = operacion[1]*operacion[2]; break;
                    case 4: operacion[3] = operacion[1]/operacion[2]; break;
                }
                
                datagrama.setData(Float.toString(operacion[3]).getBytes());
                datagrama.setLength(Float.toString(operacion[3]).getBytes().length);
                socket.send(datagrama);
                System.out.println("Mensaje enviado desde el server: "+operacion[3]);
            }
        }catch(IOException e){
            System.err.println("Error a la hora de establecer conexiones o interprentando datos, "
                    + "tal vez el cliente se cortó a la mitad y volvió a entablar conexión a mitad de cuenta");
        }
        finally{
            try {
                socket.close();
            
            } catch (Exception ex) {
                
            }
        }
    }
}
