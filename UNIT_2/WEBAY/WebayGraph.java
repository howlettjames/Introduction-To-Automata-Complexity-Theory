import java.applet.Applet;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Arc2D;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;

public class WebayGraph extends Applet{
    
    @Override
    public void paint(Graphics g){
        
        int z;
        int alto, ancho;
        setSize(1000, 500);
        setBackground(Color.WHITE);
        g.setColor(Color.RED); 
        Font f = new Font(Font.DIALOG, Font.BOLD, 15);
        g.setFont(f);
        g.drawString("DFA WEBAY", 480, 20);
        
        /*--------------------------LINEAS-----------------------------------------------------*/                       
        Graphics2D graph = (Graphics2D)g;
        graph.setColor(Color.BLACK); 
                                         //anchoFromPantalla,alturaFromPantalla,longitud(70-99),alturaFromPantalla(final)
        Line2D L1_Start = new Line2D.Double(25,250,50,250);     //*Start
        graph.draw(L1_Start);
        Line2D B_C = new Line2D.Double(93,245,202,200);       //B-C
        graph.draw(B_C);
        Line2D B_D = new Line2D.Double(94,252,204,337);       //B-D
        graph.draw(B_D);
        Line2D D_C = new Line2D.Double(220,330,220,210);       //D-C
        graph.draw(D_C);
        Line2D C_E = new Line2D.Double(240,190,400,190);       //C-E
        graph.draw(C_E);
        Line2D E_D = new Line2D.Double(395,195,240,340);       //E-D
        graph.draw(E_D);
        Line2D E_G = new Line2D.Double(440,190,602,190);       //E-G
        graph.draw(E_G);
        Line2D G_D = new Line2D.Double(605,200,240,340);       //G-D
        graph.draw(G_D);
        Line2D D_F = new Line2D.Double(240,350,400,350);       //D-F
        graph.draw(D_F);
        Line2D F_C = new Line2D.Double(410,335,230,210);       //F-C
        graph.draw(F_C);
        Line2D F_H = new Line2D.Double(440,350,600,350);       //F-H
        graph.draw(F_H);
        Line2D H_I = new Line2D.Double(640,350,800,350);       //H-I
        graph.draw(H_I);
        Line2D H_C = new Line2D.Double(610,335,230,210);       //H-C
        graph.draw(H_C);
        Line2D I_C = new Line2D.Double(810,335,230,210);       //I-C
        graph.draw(I_C);
        Line2D G_H = new Line2D.Double(620,210,620,330);       //G-H
        graph.draw(G_H);
        /*-------------------------------------------------------------------------------------*/
        
        
        /*------------------------- ARCOS (conectores) -----------------------*/
                                    //x,y,ancho,alto,inicio desde angulo,angulo,0
        
        Ellipse2D B_B = new Ellipse2D.Double(50,215,20,20);      //B-B
        graph.draw(B_B);
        Ellipse2D C_C = new Ellipse2D.Double(200,150,20,20);      //C-C 
        graph.draw(C_C);
        Arc2D C_B = new Arc2D.Double(92,195,158,80,65,118,0);     //C-B
        graph.draw(C_B);
        Ellipse2D D_D = new Ellipse2D.Double(210,370,20,20);      //D-D 
        graph.draw(D_D);
        Arc2D D_B = new Arc2D.Double(85,220,200,120,167,114,0);     //D-B
        graph.draw(D_B);
        Arc2D E_C = new Arc2D.Double(200,150,270,180,50,88,0);     //E-C
        graph.draw(E_C);
        Arc2D E_B = new Arc2D.Double(80,130,390,250,45,125,0);     //E-B
        graph.draw(E_B);
        Arc2D G_C = new Arc2D.Double(200,100,430,290,28,122,0);     //G-C
        graph.draw(G_C);
        Arc2D G_B = new Arc2D.Double(75,85,570,330,28,145,0);     //G-B
        graph.draw(G_B);
        Arc2D F_D = new Arc2D.Double(200,205,270,180,225,82,0);     //F-D
        graph.draw(F_D);
        Arc2D H_D = new Arc2D.Double(200,205,460,210,211,115,0);     //H-D
        graph.draw(H_D);
        Arc2D I_D = new Arc2D.Double(230,205,600,260,190,155,0);     //I-D
        graph.draw(I_D);
        Arc2D I_B = new Arc2D.Double(65,105,780,360,175,160,0);     //I-B
        graph.draw(I_B);
        Arc2D F_B = new Arc2D.Double(80,160,400,240,175,138,0);     //F-B
        graph.draw(F_B);
        
        /*--------------------------------------------------------------------*/
        
        /*----------------------- CONECTORES (Flechas) -----------------------*/
        Ellipse2D start_conector = new Ellipse2D.Double(50,245,8,8);     //Start
        graph.draw(start_conector);
        graph.fill(start_conector);
        Ellipse2D B_Bconector = new Ellipse2D.Double(60,230,6,6);           //B-B
        graph.draw(B_Bconector);                                           
        graph.fill(B_Bconector);
        Ellipse2D C_Cconector = new Ellipse2D.Double(208,166,6,6);           //C-C
        graph.draw(C_Cconector);                                           
        graph.fill(C_Cconector);
        Ellipse2D C_Bconector = new Ellipse2D.Double(90,233,6,6);           //C-B
        graph.draw(C_Bconector);                                           
        graph.fill(C_Bconector);
        Ellipse2D B_Cconector = new Ellipse2D.Double(200,197,6,6);           //B-C
        graph.draw(B_Cconector);                                           
        graph.fill(B_Cconector);
        Ellipse2D B_Dconector = new Ellipse2D.Double(200,333,6,6);           //B-D
        graph.draw(B_Dconector);                                           
        graph.fill(B_Dconector);
        Ellipse2D D_Dconector = new Ellipse2D.Double(215,367,6,6);           //D-D
        graph.draw(D_Dconector);                                           
        graph.fill(D_Dconector);
        Ellipse2D D_Bconector = new Ellipse2D.Double(85,266,6,6);           //D-B
        graph.draw(D_Bconector);                                           
        graph.fill(D_Bconector);
        Ellipse2D D_Cconector = new Ellipse2D.Double(216,210,6,6);           //D-C
        graph.draw(D_Cconector);                                           
        graph.fill(D_Cconector);
        Ellipse2D E_Cconector = new Ellipse2D.Double(234,175,6,6);           //E-C
        graph.draw(E_Cconector);                                           
        graph.fill(E_Cconector);
        Ellipse2D C_Econector = new Ellipse2D.Double(395,188,6,6);           //C-E
        graph.draw(C_Econector);                                           
        graph.fill(C_Econector);
        Ellipse2D E_Dconector = new Ellipse2D.Double(238,335,6,6);           //E-D
        graph.draw(E_Dconector);                                           
        graph.fill(E_Dconector);
        Ellipse2D E_Bconector = new Ellipse2D.Double(82,227,6,6);           //E-B
        graph.draw(E_Bconector);                                           
        graph.fill(E_Bconector);
        Ellipse2D G_Cconector = new Ellipse2D.Double(225,170,6,6);           //G-C
        graph.draw(G_Cconector);                                           
        graph.fill(G_Cconector);
        Ellipse2D G_Bconector = new Ellipse2D.Double(74,227,6,6);           //G-B
        graph.draw(G_Bconector);                                           
        graph.fill(G_Bconector);
        Ellipse2D E_Gconector = new Ellipse2D.Double(595,188,6,6);           //E-G
        graph.draw(E_Gconector);                                           
        graph.fill(E_Gconector);
        Ellipse2D D_Fconector = new Ellipse2D.Double(395,347,6,6);           //D-F
        graph.draw(D_Fconector);                                           
        graph.fill(D_Fconector);
        Ellipse2D F_Cconector = new Ellipse2D.Double(225,204,6,6);           //F-C
        graph.draw(F_Cconector);                                           
        graph.fill(F_Cconector);
        Ellipse2D F_Dconector = new Ellipse2D.Double(235,355,6,6);           //F-D
        graph.draw(F_Dconector);                                           
        graph.fill(F_Dconector);
        Ellipse2D F_Hconector = new Ellipse2D.Double(595,347,6,6);           //F-H
        graph.draw(F_Hconector);                                           
        graph.fill(F_Hconector);
        Ellipse2D H_Iconector = new Ellipse2D.Double(795,347,6,6);           //H-I
        graph.draw(H_Iconector);                                           
        graph.fill(H_Iconector);
        Ellipse2D H_Dconector = new Ellipse2D.Double(230,364,6,6);           //H-D
        graph.draw(H_Dconector);                                           
        graph.fill(H_Dconector);
        Ellipse2D I_Dconector = new Ellipse2D.Double(232,360,6,6);           //I-D
        graph.draw(I_Dconector);                                           
        graph.fill(I_Dconector);
        Ellipse2D I_Bconector = new Ellipse2D.Double(65,266,6,6);           //I-B
        graph.draw(I_Bconector);                                           
        graph.fill(I_Bconector);
        Ellipse2D G_Hconector = new Ellipse2D.Double(617,327,6,6);           //G-H
        graph.draw(G_Hconector);                                           
        graph.fill(G_Hconector);        
        /*--------------------------------------------------------------------*/
        
        /*------------------------------- ESTADOS ----------------------------*/
        Graphics2D graph02 = (Graphics2D)g;
        graph02.setColor(Color.BLACK);
        Ellipse2D B = new Ellipse2D.Double(55, 230, 40, 40);   //B
        graph02.draw(B);
        Ellipse2D C = new Ellipse2D.Double(200,170,40,40);      //C
        graph02.draw(C);
        Ellipse2D D = new Ellipse2D.Double(200,330,40,40);      //D
        graph02.draw(D);
        Ellipse2D E = new Ellipse2D.Double(400,170,40,40);      //E
        graph02.draw(E);
        Ellipse2D G = new Ellipse2D.Double(600,170,40,40);      //G
        graph02.draw(G);
        Ellipse2D G2 = new Ellipse2D.Double(605,175,30,30);      //G2
        graph02.draw(G2);
        Ellipse2D F = new Ellipse2D.Double(400,330,40,40);      //F
        graph02.draw(F);
        Ellipse2D H = new Ellipse2D.Double(600,330,40,40);      //H
        graph02.draw(H);
        Ellipse2D I = new Ellipse2D.Double(800,330,40,40);      //I
        graph02.draw(I);
        Ellipse2D I2 = new Ellipse2D.Double(805,335,30,30);      //I2
        graph02.draw(I2);
        
        /*--------------------------------------------------------------------*/
        
        /*--------------------------- ETIQUETAS ------------------------------*/
        Font f1 = new Font(Font.SANS_SERIF, Font.BOLD, 10);
        g.setFont(f1);
        
        g.drawString("Start", 20, 247);   //Start
        g.drawString("B", 70, 255);         //
        g.drawString("Not e,w", 25, 215);    //Start-Start   
        g.drawString("C", 216, 194);
        g.drawString("w", 203, 148);
        g.drawString("Not e,w", 120, 190);
        g.drawString("w", 135, 218);
        g.drawString("D", 216, 353);
        g.drawString("e", 147, 310);
        g.drawString("e", 217, 397);
        g.drawString("Not e,w,b", 130, 330);
        g.drawString("w", 210, 270);
        g.drawString("E", 415, 195);
        g.drawString("e", 320, 185);
        g.drawString("e", 330, 240); 
        g.drawString("w", 330, 150);
        g.drawString("Not e,w,b", 220, 124); 
        g.drawString("G", 615, 195);
        g.drawString("w", 430, 100);
        g.drawString("Not e,w,a", 330, 80);
        g.drawString("e", 470, 240);
        g.drawString("F", 416, 353);
        g.drawString("b", 320, 367);
        g.drawString("w", 285, 250);
        g.drawString("e", 330, 380);
        g.drawString("H", 616, 353);
        g.drawString("I", 819, 353);
        g.drawString("a", 520, 367);
        g.drawString("y", 720, 367);
        g.drawString("e", 430, 410);
        g.drawString("e", 515, 455);
        g.drawString("Not e,w", 515, 478);
        g.drawString("Not e,w,a", 194, 404);
        g.drawString("w", 520, 300);
        g.drawString("w", 648, 300);
        g.drawString("a", 630, 270);
        /*--------------------------------------------------------------------*/
    }
    
}
