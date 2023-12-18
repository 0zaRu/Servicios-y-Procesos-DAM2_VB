package com.mycompany.ejercicio_12;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;

/**
 *
 * @author 6002754
 */
public class Ejercicio_12 {

    public static void main(String[] args) {
        Cola cola = new Cola();
        if (!cola.ruta.exists() || cola.ruta.length() == 0) {
            System.err.println("El fichero no existe o está vacío");
            return;
        }

        HProductor productor = new HProductor(cola);
        HConsumidor consumidor = new HConsumidor(cola);

        productor.start();
        consumidor.start();

    }
}

class Cola {
    char leido;
    boolean disponible = false;
    boolean terminado = false;
    int contCaract = 0;
    File ruta = new File("Fichero.txt");

    
    public synchronized void readPut() {
        while (disponible) {
            try {
                wait();
            } catch (Exception e) {
                System.err.println("Interrumpido");
            }
        }
        disponible = false;

        try {
            RandomAccessFile archivo = new RandomAccessFile(ruta, "r");

            archivo.seek(contCaract);
            char caracterLeido = (char) archivo.read();

            archivo.close();

            leido = caracterLeido;
            contCaract += 1;
            disponible = true;

            notify();
            
        } catch (IOException e) {
        }
    }

    public synchronized void get() {
        while (!disponible) {
            try {
                wait();
            } catch (Exception e) {
                System.err.println("Interupción");
            }
        }
        disponible = false;
        notify();
        System.out.print(leido);
        
        if (ruta.length() == contCaract) {
            System.out.println("\n\nArchivo terminado");
            terminado = true;
        }
    }
}