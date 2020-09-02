/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package numeros.binarios;
import java.util.Random;
import java.util.Scanner;
import java.io.File;
import java.io.FileWriter;
import java.io.*;
import java.awt.Graphics;
import java.awt.Image;
import javax.swing.JPanel;
/**
 *
 * @author Ivan Trejo
 */
public class NumerosBinarios extends JPanel{
    
    public static void main(String[] args) {
        
        int desde = 2;
        int hasta;
        boolean esPrimo;
        int ran;
        
        String option;
        Scanner stdIn = new Scanner(System.in);
        Scanner stdOn = new Scanner(System.in);
        Random  rnd = new Random();        

        FileWriter archivo = null;
        PrintWriter pw= null;

        FileWriter archivo2 = null;
        PrintWriter pw2= null;
        
        do {           
            System.out.println ("Menu de la Calculadora de Números Primos\n");
            System.out.println ("1. Introducir un número");
            System.out.println ("2. Random");
            System.out.println ("3. Gráfica de 1s");
            System.out.println ("4. Salir");
            System.out.println ("Selecciona: ");
            int entrada= stdIn.nextInt ();
            int n;
            switch (entrada) {
            case 1 :                
                System.out.print("Hasta que Numero Quiere que Calcule Los Numeros Primos:");
                n = stdOn.nextInt();
                System.out.print(" ó en binario: ");
                System.out.println(Integer.toBinaryString(n));
                try{
                    archivo2 = new FileWriter("Archivo de Numeros Primos.txt");
                    pw2 = new PrintWriter(archivo2);
                    pw2.print("{");
                    System.out.print("{");
                    hasta=n;
                      
                    for (int i = desde; i <= hasta; i++) {
                        esPrimo = true;
     
                        for (int j = 2; j <= Math.sqrt(i) && esPrimo; j++) {
                            if (i % j == 0) {
                                esPrimo = false;
                            }
                        }
     
                        if (esPrimo) {
                            //String valor = ",";
                            //System.out.println(i+valor);
                            pw2.print(Integer.toBinaryString(i));
                            pw2.print(",");
                            System.out.print(Integer.toBinaryString(i));
                            System.out.print(",");
                        }
                    }
                pw2.print("}");
                System.out.print("\b}\n");
                }
                catch(Exception e){
                    e.printStackTrace();
                }
                finally{
                    try{
                        if(archivo2!=null)
                            archivo2.close();
                    }
                    catch(Exception e2){
                        e2.printStackTrace();
                    }
                }
                break;

            case 2:                                        
                System.out.print("El número random fue: "); 
                ran=rnd.nextInt(1000);
                System.out.print(Integer.toBinaryString(ran));
                System.out.print(" ó en decimal: ");
                System.out.print(ran+"\n");
                
                try{
                    archivo= new FileWriter("Archivo de Numeros Primos Random.txt");
                    pw = new PrintWriter(archivo);
                    pw.print("{");
                    System.out.print("{"); 
                    hasta = ran;
     
                    for (int i = desde; i <= hasta; i++) {
                        esPrimo = true;
     
                        for (int j = 2; j <= Math.sqrt(i) && esPrimo; j++) {
                            if (i % j == 0) {
                                esPrimo = false;
                            }
                        }
     
                        if (esPrimo) {
                            //String valor = ",";
                            //System.out.print(i+valor);
                            pw.print(Integer.toBinaryString(i));
                            pw.print(",");
                            System.out.print(Integer.toBinaryString(i));
                            System.out.print(",");
                        }
                    }
                    pw.print("}");
                    System.out.print("\b}\n");
                }
                catch(Exception e){
                    e.printStackTrace();
                }
                finally{
                    try{
                        if(archivo!=null)
                            archivo.close();
                    }
                    catch(Exception e2){
                        e2.printStackTrace();
                    }
                }
                break;
            case 3:
                Grafica ventana = new Grafica(); 
                ventana.setVisible(true);
            break;
            case 4:                                         
                System.out.print("Gracias por usar el programa \n");
                System.exit(0); 
                break;
            
            default:            
            System.out.printf( "Número no valido\n" );
            break;
            }
            System.out.println("¿Desea Reiniciar el Programa? s/n");  
            option=stdIn.next();
        }
        while(option.equals("s"));  
    }
}