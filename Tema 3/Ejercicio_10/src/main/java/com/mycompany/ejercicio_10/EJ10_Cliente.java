package com.mycompany.ejercicio_10;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Scanner;

/**
 *
 * @author arube
 */
public class EJ10_Cliente {

    static int PUERTO = 9876;
    static InetAddress SERVERIP;
    static Scanner kb = new Scanner(System.in);
    
    public static void main(String[] args) {
        System.out.println("TERMINAL CLIENTE");
        DatagramSocket socket = null;
        boolean salir = false;
        
        try{            
            SERVERIP = InetAddress.getLocalHost();
            do{
                int op = mostrarMenu();
                byte[] envio = Integer.toString(op).getBytes();
                limpiar();
                
                switch(op){
                    case 1: case 2: case 3: case 4:
                        //Podría haber enviado todo junto y hacer un split tambien, no se cual sea mejor opción
                        //Quise modularizar pero solo podría haberlo hecho con los 2 primeros socket, el tercero necesita ser el mismo que recibe
                        DatagramPacket datagrama = new DatagramPacket(envio, envio.length, SERVERIP, PUERTO);
                        socket = new DatagramSocket();
                        socket.send(datagrama);
                        
                        System.out.print("\nIntroduce el primer numero a operar: ");
                        float num = kb.nextFloat();
                        envio = Float.toString(num).getBytes();
                        
                        datagrama = new DatagramPacket(envio, envio.length, SERVERIP, PUERTO);
                        socket = new DatagramSocket();
                        socket.send(datagrama);
                        
                        System.out.print("\nIntroduce el segundor numero a operar: ");
                        num = kb.nextFloat();
                        envio = Float.toString(num).getBytes();
                        
                        datagrama = new DatagramPacket(envio, envio.length, SERVERIP, PUERTO);
                        socket = new DatagramSocket();
                        socket.send(datagrama);
                        
                        
                        byte[] buffer = new byte[1024];
                        datagrama.setData(buffer);
                        datagrama.setLength(buffer.length);
                        
                        socket.receive(datagrama);

                        String recibido = new String(datagrama.getData());
                        System.out.println("Resultado: "+ recibido);
                        
                    break;
                    
                    case 9:
                        System.out.println("Se va a salir del programa");
                        salir = true;
                    break;
                    
                    default:
                        System.out.println("Valor introducido no válido ...");
                        
                }
                kb.nextLine();
                System.out.println("Pulse una enter para continuar ...");
                kb.nextLine();
                
                limpiar();
                
            }while (!salir);
        }catch(IOException e){
            System.err.println("No se pudo establecer conexión con el servidor");
        
        }catch(InputMismatchException ie){
            System.err.println("Debes introducir numeros en las casillas numéricas.");
        
        }

        kb.close();
    }
    
    /**No usado pero funcina*/
    private static void envioUDP(byte[] paquete) throws SocketException, IOException{
        DatagramPacket datagrama = new DatagramPacket(paquete, paquete.length, SERVERIP, PUERTO);
        DatagramSocket socket = new DatagramSocket();
        socket.send(datagrama);
    }
    
    /**No usado porque se traba, creo que porque debe usar el mismo datagram Packet y socket que usa para enviar, para recibir*/
    private static String recibidoUDP() throws SocketException, IOException{
        byte[] buffer = new byte[1024];
        
        DatagramPacket datagrama = new DatagramPacket(buffer, buffer.length, SERVERIP, PUERTO);
        DatagramSocket socket = new DatagramSocket();
        socket.receive(datagrama);
        
        return Arrays.toString(datagrama.getData());
    }
    
    private static int mostrarMenu() throws InputMismatchException{
        System.out.println("------ Menú ------");
        System.out.println("1 - Sumar");
        System.out.println("2 - Restar");
        System.out.println("3 - Multiplicar");
        System.out.println("4 - Dividir");
        System.out.println("9 - Salir");
        System.out.println("-------------------");
        
        System.out.print("\n\tElige una opción: ");
        return kb.nextInt();
    }
    
    static void limpiar(){
        for(int i = 0; i < 30; i++){
            System.out.println("");
        }
    }
    
}
