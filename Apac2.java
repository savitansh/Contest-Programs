import java.util.ArrayList;
import java.util.Deque;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;


public class Apac2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int T;
		Scanner sc = new Scanner(System.in);
		
		T= Integer.parseInt(sc.next());
		for(int i1=1; i1<=T; i1++){
			Deque<String> deq = new LinkedList<String>();
			Deque<String> tmp = new LinkedList<String>();
			int n;
			String[] start = new String[10001];
			String[] end = new String[10001];
			
			n = Integer.parseInt(sc.next());
			for(int i=1; i<=n; i++){
				start[i] = sc.next();
				end[i] = sc.next();
			}
			deq.addLast(start[1]);
			//deq.addLast(end[1]);
			tmp.addLast(start[1]);
			//4tmp.addLast(end[1]);
			
			while(!tmp.isEmpty()){
				String strt = tmp.getFirst();
				tmp.remove();
				for(int i=1; i<=n; i++){
					if(strt.equals(end[i]) && end[i] != ""){
						deq.addFirst(start[i]);
						tmp.add(start[i]);
						end[i] = "";
						start[i] = "";
					}else if(strt.equals(start[i]) && end[i] != ""){
						deq.addLast(end[i]);
						tmp.add(end[i]);
						end[i] = "";
						start[i] = "";
					}
				}
			}
			
			Iterator<String> iter = deq.iterator();
			String source = iter.next();
			String dest = iter.next();
			System.out.print("Case #"+i1+": ");
			System.out.print(source+"-"+dest);
			while(iter.hasNext()){
				source = new String(dest);
				dest = iter.next();
				System.out.print(" "+source+"-"+dest);
			}	
			System.out.println();
		}
		
	}

}
