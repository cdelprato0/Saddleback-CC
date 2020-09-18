
import java.io.PrintStream;
import java.util.Random;
import java.util.Scanner;


/**
 *
 * @author chazd
 */
public class RPSModel {
 
    private Random rand;
   
    
    public class Players{
        private String pick;
        private boolean decision;
        
        private Players(){
            decision = false;
        }
        
        void setPick(String newPick){
            pick = newPick;
        }
        
        void setDesicion(boolean setD){
            decision  = setD;
        }
        
        String getPick(){
            return pick;
        }
        
        boolean getDecision(){
            return decision;
        }
    }
    
    public Players player1Name, player2Name;
    
    public RPSModel(){
        player1Name = new Players();
        player2Name = new Players();
        rand = new Random();
    }
    
    public void player1Pick(String p1Pick){
        player1Name.pick = p1Pick;
        player1Name.decision = true;
    }
    
    public void player2Pick(String p2Pick){
        player2Name.pick = p2Pick;
        player2Name.decision = true;
    }
    
    public void clearPlayer1(){
        player1Name.pick = null;
        player1Name.decision = false;
    }
    
    public void clearPlayer2(){
        player2Name.pick = null;
        player2Name.decision = false;
    }
    
    public String playGame(String player1P, String player2P){
        
        //if( player1P.equals(this) ){
            switch(player1P){
                case "rock": 
                    switch(player2P){
                        case "rock": return " you tie";
                        
                        case "paper": return " you loss";
                        
                        case "scissors": return " you won";
                        default: return " you won";
                    }
                    
                case "paper":
                        switch(player2P){
                        case "rock": return " you won";
                        
                        case "paper": return " you tie";
                        
                        case "scissors": return " you loss";
                        default: return " you won";
                    }
                    
                case "scissors":
                        switch(player2P){
                        case "rock": return " you loss";
                        
                        case "paper": return " you won";
                        
                        case "scissors": return " you tie";
                        default: return " you won";
                    }
                    
                default: if(player2P.equals("rock") || player2P.equals("paper")
                                || player2P.equals("scissors")){
                                return " you loss";
                            }else{
                                return " you tie";
                            }
            }
       // }
            
    }
    protected String processIO(Scanner input, PrintStream output) {

        String player1 = input.next();
        String player2 = input.next();
        StringBuilder out = new StringBuilder();
        int winCount1 = 0;
        int lossCount1 = 0;
        int tieCount1 = 0;
        int winCount2 = 0;
        int lossCount2 = 0;
        int tieCount2 = 0;

        
        out.append("New roundRobin players: ").append(player1).append(", ").append(player2).append("\n");

            String p1Move = input.next();
            String p2Move = input.next(); 
        
        while(input.hasNext() && !p2Move.equals("quit") && !p1Move.equals("quit")){
              
            String results;
            String results2;

            RPSModel play1 = new RPSModel();
            RPSModel play2 = new RPSModel();
            RPSModel playG = new RPSModel();

            String out1 = p1Move;
            String out2 = p2Move;

            p1Move = p1Move.toLowerCase();
            p2Move = p2Move.toLowerCase();


            play1.player1Pick(p1Move);
            play2.player2Pick(p2Move);


            results = playG.playGame(p1Move, p2Move);

            out.append("You chose ").append(out1).append(" ").append(player2).append(" ").append(out2).append(results).append("\n");
            //System.out.println("You chose " + out1 + " " + player2 + " " + out2 + results);

            results2 = playG.playGame(p2Move, p1Move);
            out.append("You chose ").append(out2).append(" ").append(player1).append(" ").append(out1).append(results2).append("\n");
           // System.out.println("You chose " + out2 + " " + player1 + " " + out1 + results2);
           
           
            p1Move = input.next();
            if(!input.hasNext()){
                break;
            }
            p2Move = input.next();

            switch (results) {
                case " you won":
                    winCount1++;
                    break;
                case " you tie":
                    tieCount1++;
                    break;
                default:
                    lossCount1++;
                    break;
            }

            switch (results2) {
                case " you won":
                    winCount2++;
                    break;
                case " you tie":
                    tieCount2++;
                    break;
                default:
                    lossCount2++;
                    break;
            }
        }
        
    
    out.append(player1).append(" ").append(winCount1).append("-").append(lossCount1).append("-").append(tieCount1).append("\n");
    out.append(player2).append(" ").append(winCount2).append("-").append(lossCount2).append("-").append(tieCount2).append("\n"); 
    if(winCount1 > winCount2){
       out.append(player1).append(" defeated ").append(player2).append(" ").append(winCount1).append(" to ").append(winCount2);
    }else if(winCount2 > winCount1){
        out.append(player2).append(" defeated ").append(player1).append(" ").append(winCount2).append(" to ").append(winCount1);
    }else{
        out.append(player1).append(" and ").append(player2).append(" tied");
    } 
    return out.toString();
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        RPSModel game = new RPSModel();
        
       System.out.println(game.processIO(input, System.out));
            
   
    }
}

//broncos
//chargers
//scissors
//rock
//Rack
//rock
//RoCK
//rOck
//papoer
//paper
//paper
//scissors