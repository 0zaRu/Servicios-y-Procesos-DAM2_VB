package com.mycompany.ejemplo_1_waitnotify;

/**
 *
 * @author 6002754
 */
public class MiHilo extends Thread {

    Object testigo;

    public MiHilo(String name, Object testigo) {
        setName(name);
        this.testigo = testigo;
    }

    @Override
    public void run() {
        try {
            for (int i = 0; i < 10; i++) {
                synchronized (testigo) {
                    System.out.print(getName());

                    if (getName().equals("PING\t")) {
                        testigo.wait();
                        testigo.notify();
                    } else {
                        testigo.notify();
                        testigo.wait();
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
