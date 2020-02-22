package main;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;

public class Main {
    static class Bid{
        String name;
        int valoare;

        public Bid(String na, int val){
            name=na;
            valoare=val;
        }
    }

    static ArrayList<Bid> all= new ArrayList<>();
    static int initialBid;
    static int buyNow;

    public static String readFromFile(String fileName) throws IOException {
        String data = "";
        data = new String(Files.readAllBytes(Paths.get(fileName)));
        return data;
    }

    public static void getInfo(String data){
        data=data.replace(" ","");
        String[] s = data.split(",");
        initialBid=Integer.parseInt(s[0]);
        buyNow = Integer.parseInt(s[1]);
        if(buyNow<initialBid)
            buyNow=99999999;
        for(int i=2;i<s.length;i+=2){
            Bid b = new Bid(s[i], Integer.parseInt(s[i+1]));
            all.add(b);
        }
    }

    public static Bid getMaximumBid(ArrayList<Bid> l){
        Bid maxBid = new Bid("-1", initialBid-1);
        for (int i=0;i<l.size()-1;i++){
            Bid b = l.get(i);
            if(b.valoare>maxBid.valoare){
                maxBid.name=b.name;
                maxBid.valoare=b.valoare;
            }

        }
        return maxBid;
    }
    public static Bid getLastBid(ArrayList<Bid> l){
        if(!l.isEmpty())
            return l.get(l.size()-1);
        return new Bid("?",-1);
    }

    public static ArrayList<Bid> solve(ArrayList<Bid> all){
        ArrayList<Bid> bids = new ArrayList<>();
        ArrayList<Bid> solution = new ArrayList<>();
        solution.add(new Bid(all.get(0).name,initialBid));
        for(Bid b: all){
            bids.add(b);
            if(b.valoare==initialBid&&!OtherBidders(all, b, bids.size())){
               // solution.add(new Bid(getLastBid(solution).name,buyNow));
                solution.add(new Bid(getLastBid(solution).name,buyNow));
                break;
            }
            if(!b.name.equals(getLastBid(solution).name)&&OtherBidders(all, b, bids.size())){
                if(getMaximumBid(bids).valoare>=buyNow) {
                    solution.add(new Bid(getLastBid(solution).name, buyNow));
                    break;
                }
                if(b.valoare>getMaximumBid(bids).valoare)
                    solution.add(new Bid(b.name,getMaximumBid(bids).valoare+1));
                if(b.valoare<getMaximumBid(bids).valoare&&OtherBidders(all, b, bids.size()))
                    solution.add(new Bid(getMaximumBid(bids).name, b.valoare+1));
                if(b.valoare==getMaximumBid(bids).valoare&&OtherBidders(all, b, bids.size()))
                    solution.add(new Bid(getMaximumBid(bids).name, b.valoare));
            }
            else if((!OtherBidders(all, b, bids.size()))&&(bids.size()==all.size())&& (b.valoare!=getMaximumBid(bids).valoare)){
                if(getMaximumBid(bids).valoare>=buyNow){
                    solution.add(new Bid(getLastBid(solution).name,buyNow));
                    break;
                }
                if(b.valoare<getMaximumBid(bids).valoare)
                    solution.add(new Bid(getMaximumBid(bids).name,b.valoare+1));
                else
                    solution.add(new Bid(b.name,getMaximumBid(bids).valoare+1));
                break;
            }
            else if(!OtherBidders(all, b, bids.size())&&bids.size()==all.size()){
                if(getMaximumBid(bids).valoare>=buyNow) {
                    solution.add(new Bid(getLastBid(solution).name,buyNow));
                    break;
                }
                solution.add(new Bid(getMaximumBid(bids).name,getMaximumBid(bids).valoare));
                break;
            }
            else if(!OtherBidders(all, b, bids.size())&&bids.size()<all.size()){
                if(getMaximumBid(bids).valoare>=buyNow) {
                    solution.add(new Bid(getLastBid(solution).name,buyNow));
                    break;
                }
                solution.add(new Bid(b.name,getMaximumBid(bids).valoare+1));
                break;
            }
        }
        return solution;
    }
    public static boolean OtherBidders(ArrayList<Bid> l, Bid b, int index){
        for(int i=index;i<l.size();i++){
            Bid p = l.get(i);
            if(!p.name.equals(b.name))
                return true;
        }
        return false;
    }
    public static void showResult(ArrayList<Bid> l){
        String s= "-,"+initialBid;
        for(Bid b:l){
            s+=",";
            s+=b.name;
            s+=",";
            s+=b.valoare;
        }
        System.out.println(s);
    }
    public static void main(String[] args) throws IOException {
        String data = readFromFile("C:\\Users\\Iuliu\\OneDrive\\Desktop\\Auction System\\1.txt");
        getInfo(data);
        showResult(solve(all));
    }

}
