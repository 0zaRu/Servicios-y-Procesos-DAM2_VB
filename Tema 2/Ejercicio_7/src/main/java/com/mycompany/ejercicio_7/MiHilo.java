package com.mycompany.ejercicio_7;

/**
 *
 * @author 6002754
 */
public class MiHilo extends Thread{
    
    public MiHilo(String name){
        this.setName(name);
    }

    @Override
    public void run() {
        try {
            while(true){
                if(activeCount() == 2)
                    System.out.println("Soy el "+getName()+" y soy el último superviviente.");
                else
                    System.out.println("Mi nombre es: "+getName());

                sleep(1000);
            }
        } catch (InterruptedException ex) {
        }
        System.out.println("\tSoy "+getName()+" y he muerto.");
    }
}
