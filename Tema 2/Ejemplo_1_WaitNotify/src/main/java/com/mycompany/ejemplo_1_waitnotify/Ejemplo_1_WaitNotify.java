package com.mycompany.ejemplo_1_waitnotify;

/**
 *
 * @author 6002754
 */
public class Ejemplo_1_WaitNotify {

    static Object testigo = "testigo";
    
    public static void main(String[] args) {
        MiHilo h1 = new MiHilo("PING\t", testigo);
        h1.start();
        
        MiHilo h2 = new MiHilo("PONG\n", testigo);
        h2.start();
    }
}