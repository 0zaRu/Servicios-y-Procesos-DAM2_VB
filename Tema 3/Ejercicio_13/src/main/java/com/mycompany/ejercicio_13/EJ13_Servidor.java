package com.mycompany.ejercicio_13;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.util.ArrayList;

/**
 *
 * @author arube
 */
public class EJ13_Servidor {
    
    private static final ArrayList<String> preguntas = new ArrayList<>();
    private static final ArrayList<String> respuestas = new ArrayList<>();
    
    public static void main(String[] args) {
        System.out.println("TERMINAL SERVIDOR");
        int puerto = 9876;
        
        DatagramSocket socket = null;
        establecePreguntasRespuestas();
        
        try {
            socket = new DatagramSocket(puerto);
            while(true){
                
                
                
            }
        }catch(IOException e){
            System.err.println("Error a la hora de establecer conexiones o interprentando datos, "
                    + "tal vez el cliente se cortó a la mitad y volvió a entablar conexión a mitad de juego");
        }
        finally{
            try {
                socket.close();
            
            } catch (Exception ex) {
                
            }
        }
    }
    
    private static void establecePreguntasRespuestas(){
        preguntas.add("¿Cuál es la capital de Francia?\nA) Berlín\nB) París\nC) Madrid\nD) Roma");
        respuestas.add("B");
        
        preguntas.add("¿Cuántos planetas hay en nuestro sistema solar?\nA) 7\nB) 10\nC) 9\nD) 9");
        respuestas.add("D");
        
        preguntas.add("¿Cuál es el río más largo del mundo?\nA) Nilo\nB) Amazonas\nC) Yangtsé\nD) Misisipi");
        respuestas.add("A");
        
        preguntas.add("¿Cuál es el mejor personaje de League of Legends?\nA) Sett\nB) Teemo\nC) Aurelion Sol\nD) Yumi");
        respuestas.add("A");
        
        preguntas.add("¿Mejor ejercicio del día de pierna?\nA) Prensa\nB) Sentadilla\nC) Press Banca\nD) Gemelos");
        respuestas.add("C");
    }
}
