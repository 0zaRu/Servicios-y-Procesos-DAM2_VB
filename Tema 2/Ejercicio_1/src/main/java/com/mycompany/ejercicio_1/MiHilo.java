/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.ejercicio_1;

/**
 *
 * @author 6002754
 */
public class MiHilo extends Thread{

    @Override
    public void run() {
        System.out.println("Hola soy el hilo '"+getName()+
                           "' con id '"+getId()+
                           "', prioridad "+getPriority()+
                           " y en mi grupo hay '"+activeCount()+"' hilos.");
    }
}
