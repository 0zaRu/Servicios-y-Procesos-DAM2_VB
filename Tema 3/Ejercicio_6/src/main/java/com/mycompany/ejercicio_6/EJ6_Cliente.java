package com.mycompany.ejercicio_6;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.InetAddress;
import java.net.Socket;
import java.util.InputMismatchException;
import java.util.Scanner;

/**
 *
 * @author arube
 */
public class EJ6_Cliente {

    static int PUERTO = 9876;
    static Scanner kb = new Scanner(System.in);
    
    public static void main(String[] args) {
        System.out.println("TERMINAL CLIENTE");
        
        Socket cliente = null;
        DataOutputStream doSalida = null;
        DataInputStream diEntrada = null;
        boolean salir = false;
        
        try{
            InetAddress serverIP = InetAddress.getLocalHost();
            cliente = new Socket(serverIP, PUERTO);
            
            do{
                int op = mostrarMenu();
                
                limpiar();
                
                switch(op){
                    case 1: case 2: case 3: case 4:
                        doSalida = new DataOutputStream(cliente.getOutputStream());
                        doSalida.writeFloat(op);
                        
                        System.out.print("\nIntroduce el primer numero a operar: ");
                        float num = kb.nextFloat();
                        doSalida = new DataOutputStream(cliente.getOutputStream());
                        doSalida.writeFloat(num);
                        
                        System.out.print("\nIntroduce el segundor numero a operar: ");
                        num = kb.nextFloat();
                        doSalida = new DataOutputStream(cliente.getOutputStream());
                        doSalida.writeFloat(num);
                        
                        diEntrada = new DataInputStream(cliente.getInputStream());
                        System.out.println("EL SERVIDOR DICE COOMO RESULTADO: "+ diEntrada.readFloat());
                        
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
        
        finally{
            try {
                
                doSalida.close();
                diEntrada.close();
                cliente.close();
                
            } catch (Exception ex) {
                
            }
        }
        kb.close();
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
