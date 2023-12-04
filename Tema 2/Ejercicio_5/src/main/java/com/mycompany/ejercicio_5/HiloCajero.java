package com.mycompany.ejercicio_5;

import static com.mycompany.ejercicio_5.Ejercicio_5.inicio;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author 6002754
 */
public class HiloCajero extends Thread{
    
    int nClientesAtend = 0;
    
    public HiloCajero(String name){
        setName(name);
    }

    @Override
    public void run() {
        Random rand = new Random();
        int nClientes = rand.nextInt(10-5)+5;
        
        for(int i = 0; i < nClientes; i++){
            Cliente llegado = new Cliente(rand.nextInt(20-1)+1, i+1);
            
            long actual = System.nanoTime();
            System.out.println("¡Bienvenido Cliente "+llegado.numCliente+"!, le atiende "+getName()+", hoy antendí a "+nClientesAtend+" clientes y llevo "+(actual-inicio)/1e9+"'' trabajados");
            
            nClientesAtend++;
            for(int j = 0; j < llegado.nProductos; j++){
                float nSegPorProduct = rand.nextFloat(0.3f - 0.1f) + 0.1f;
                
                try {
                    sleep((int)(nSegPorProduct*1000));
                } catch (InterruptedException ex) {
                    Logger.getLogger(HiloCajero.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
            actual = System.nanoTime();
            System.out.println("¡Adiós Cliente "+llegado.numCliente+"!, le ha atiendido "+getName()+", hoy antendí a "+nClientesAtend+" clientes y llevo "+(actual-inicio)/1e9+"'' trabajados");
        }
        
        long acaba = System.nanoTime();
        System.out.println("\tSoy el "+getName()+" y he acabado mi turno antendiendo a "+nClientesAtend+" a lo largo de "+(acaba-inicio)/1e9+"''.");
    }
    
    
}
