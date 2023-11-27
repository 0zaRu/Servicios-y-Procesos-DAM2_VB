package com.mycompany.ejercicio_2;

/**
 *
 * @author 6002754
 */
public class MiHilo extends Thread{
    
    int tipo;

    public MiHilo(int tipo) {
        this.tipo = tipo;
    }
    
    @Override
    public void run() {
        if(tipo == 1){
            for (int i = 1; i <= 30; i++) {
                System.out.print(i+"\t");

                if(i == 10 || i == 20)
                    System.out.println("");
            }
            System.out.println("");
        
        }else{
            for (int i = 0; i < 26; i++) {
                System.out.print((char)('a'+i)+"\t");

                if(i == 9 || i == 19)
                    System.out.println("");
            }
            System.out.println("");
        }
    }

}
