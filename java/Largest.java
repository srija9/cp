import java.util.Scanner;
import java.util.ArrayList;

public class Largest{

    public static void partition(ArrayList<Integer> a, int i, int j, int mid){
        int n1 = mid-i+1;
        int n2 = j-mid;
        int[] a1 = new int[n1];
        int[] a2 = new int[n2];
        int k=i;

        for(int p=0; p<n1; p++){
            a1[p] = a.get(i+p);
        }

        for(int p=0; p<n2; p++){
            a2[p] = a.get(mid+1+p);
        }
        
        int p=0, q=0;
        a.clear();

        while(p<n1 && q<n2){
            if(a1[p]>a2[q]){
                // a[k]=a1[p];
                a.add(a1[p]);
                p++;
            }else{
                // a[k] = a2[q];
                a.add(a2[q]);
                q++;
            }
            // k++;
        }

        while(p<n1){
            // a[k]=a1[p];
            a.add(a1[p]);
            p++;
            // k++;
        }

        while(q<n2){
            // a[k]=a2[q];
            a.add(a2[q]);
            q++;
            // k++;
        }
    }

    public static void sort(ArrayList<Integer> a, int i, int j){

       if(i<j){
        int mid = i+(j-i)/2;
        sort(a, i, mid);
        sort(a, mid+1, j);
        partition(a, i, j, mid);
       }
    }



    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String str = s.nextLine();
        System.out.println(str);

        ArrayList<Integer> odd = new ArrayList<Integer>();
        ArrayList<Integer> even = new ArrayList<Integer>();

        for(int i=0; i<str.length(); i++){
            Character ch = str.charAt(i);
            int num = Integer.parseInt(String.valueOf(ch));
            // System.out.println(ch);
            if(i%2 == 0){
                even.add(num);
            }else{
                odd.add(num); 
            }
        }

        System.out.println(odd);
        System.out.println(even);

        sort(odd, 0, odd.size()-1);
        sort(even, 0, even.size()-1);

        System.out.println(odd);
        System.out.println(even);
        
        ArrayList<Integer> ans = new ArrayList<Integer>();
        int len = Math.min(odd.size(), even.size());

        int i=0;
        for(i=0; i<len; i++){
            ans.add(even.get(i));
            ans.add(odd.get(i));
        }
        if(i<even.size()){
            ans.add(even.get(i));
        }
        
        StringBuilder sb = new StringBuilder();
        for(Integer num : ans){
            sb.append(num.toString());
        }
        String s1 = sb.toString();
        System.out.println(s1);

    }
}