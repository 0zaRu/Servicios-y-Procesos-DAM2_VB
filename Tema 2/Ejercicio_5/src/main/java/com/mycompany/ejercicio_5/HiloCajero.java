package com.mycompany.ejercicio_5;

import static com.mycompany.ejercicio_5.Ejercicio_5.clientes;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author 6002754
 */
public class HiloCajero extends Thread{
    
    int nClientesAtend = 0;
    float nSegundosTrabajados = 0;
    
    public HiloCajero(String name){
        setName(name);
    }

    @Override
    public void run() {
        Random rand = new Random();
        int nClientes = rand.nextInt(10-5)+5;
        
        for(int i = 0; i < nClientes; i++){
            Cliente llegado = clientes.remove(0);
            
            System.out.println("¡Bienvenido Cliente "+llegado.numCliente+"!, le atiende "+getName()+", hoy antendí a "+nClientesAtend+" clientes y llevo "+nSegundosTrabajados+"'' trabajados");
            
            nClientesAtend++;
            for(int j = 0; j < llegado.nProductos; j++){
                float nSegPorProduct = rand.nextFloat(0.3f - 0.1f) + 0.1f;
                nSegundosTrabajados += nSegPorProduct;
                
                try {
                    sleep((int)(nSegPorProduct*1000));
                } catch (InterruptedException ex) {
                    Logger.getLogger(HiloCajero.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
            
            System.out.println("¡Adiós Cliente "+llegado.numCliente+"!, le ha atiendido "+getName()+", hoy antendí a "+nClientesAtend+" clientes y llevo "+nSegundosTrabajados+"'' trabajados");
        }
        
        System.out.println("\tSoy el "+getName()+" y he acabado mi turno antendiendo a "+nClientesAtend+" a lo largo de "+nSegundosTrabajados+"''.");
    }
    
    
}
