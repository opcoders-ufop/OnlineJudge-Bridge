
package bridge;

import java.io.BufferedInputStream;
import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;

/**
 *
 * @author luisa
 */
public class Bridge {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Scanner k = new Scanner(new BufferedInputStream(System.in));
        Vector<Integer> v = new Vector<Integer>();
        Vector<Integer> vEnd = new Vector<Integer>();
        Vector<Integer> vOut = new Vector<Integer>();
        int cont = 0;
        
        int nCases = k.nextInt();
        
        for(int i = 0; i < nCases; i++){
            //String c = k.next();
            int nPeople = k.nextInt();
            for(int j = 0; j < nPeople; j++){
                v.add(k.nextInt());
            }
            Collections.sort(v);
            while(vEnd.size() != nPeople){
                //System.out.println(v.get(0)+" "+v.get(1));
                vOut.add(v.get(0));
                vOut.add(v.get(1));
                cont+=v.get(1);
                vEnd.add(v.get(0));
                vEnd.add(v.get(1));
                v.removeElementAt(0);
                v.removeElementAt(0);
                if(!v.isEmpty()){
                    Collections.sort(vEnd);
                    v.add(vEnd.get(0));
                    //System.out.println(vEnd.get(0));
                    vOut.add(vEnd.get(0));
                    cont+=vEnd.get(0);
                    vEnd.removeElementAt(0);
                }
            }
            v.clear();
            vEnd.clear();
            System.out.println(cont);
            while(!vOut.isEmpty()){
                System.out.println(vOut.get(0)+" "+vOut.get(1));
                vOut.removeElementAt(0);
                vOut.removeElementAt(0);
                if(!vOut.isEmpty()){
                    System.out.println(vOut.get(0));
                    vOut.removeElementAt(0);
                }
            }
            vOut.clear();
        }
        
    }
    
}
