package com.mycompany.ejercicio_13;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

/**
 *
 * @author arube
 */
public class Informacion implements Serializable{

    Map<String, Integer> tabla = new HashMap<String, Integer>();
    
    String[] preguntas = {
        "¿Cuál es la capital de Francia?",
        "¿Cuántos planetas hay en nuestro sistema solar?",
        "¿Cuál es el río más largo del mundo?",
        "¿Cuál es el mejor personaje de League of Legends?",
        "¿Mejor ejercicio del día de pierna?"
    };

    String[][] respuestas = {
        {"A) Berlín", "B) París",      "C) Madrid",       "D) Roma"},
        {"A) 7",      "B) 8",          "C) 9",            "D) 10"},
        {"A) Nilo",   "B) Amazonas",   "C) Yangtsé",      "D) Misisipi"},
        {"A) Sett",   "B) Teemo",      "C) Aurelion Sol", "D) Yumi"},
        {"A) Prensa", "B) Sentadilla", "C) Press Banca",  "D) Gemelos"}
    };

    public String[] getRespuestasValidas(){
        return new String[]{"B", "D", "A", "A", "C"};
    }
    
    public ArrayList<String> ejecutaPregunta(){
        Scanner kb = new Scanner(System.in);
        
        ArrayList<String> respuestasDadas = new ArrayList<>();
        for (int i=0; i < preguntas.length; i++){
            limpiaPantalla();
            System.out.println(preguntas[i]);
            
            for (int j=0; j < respuestas[i].length; j++)
                System.out.println(respuestas[i][j]);
            
            System.out.print("\n\n=========\n\tRespuesta: ");
            respuestasDadas.add(kb.nextLine());
                    
        }
        kb.close();
        return respuestasDadas;
    }
    
    public synchronized void addPuntos(String nombre, int puntuacion ){
        tabla.put(nombre, puntuacion);
    }
    
    public void verTabla(){
        List<Map.Entry<String, Integer>> list = new ArrayList<>(tabla.entrySet());
        list.sort(Collections.reverseOrder(Map.Entry.comparingByValue()));
        
        int cont = 0;
        
        limpiaPantalla();
        for (Map.Entry<String, Integer> entry : list){ 
            cont ++;
            System.out.printf("Usuario: %-25s|\tAciertos: %3d\n", entry.getKey(), entry.getValue());
            
            if(cont == 5) break;
        }
        
        System.out.println("\n\nEn total han participado "+tabla.size()+" jugadores.");
    }

    public String[] getPreguntas() {
        return preguntas;
    }

    public void setPreguntas(String[] preguntas) {
        this.preguntas = preguntas;
    }

    public String[][] getRespuestas() {
        return respuestas;
    }

    public void setRespuestas(String[][] respuestas) {
        this.respuestas = respuestas;
    }

    public Map<String, Integer> getTabla() {
        return tabla;
    }

    public void setTabla(Map<String, Integer> tabla) {
        this.tabla = tabla;
    }
    
    public static void limpiaPantalla(){
        for(int i = 0; i < 30; i++){
            System.out.println(".");
        }
    }
}
