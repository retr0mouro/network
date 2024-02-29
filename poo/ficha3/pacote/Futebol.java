package pacote;

public class Futebol{
    private String home;
    private String outside;
    private int state;
    private String event;

    public Futebol(String home, String outside, int state, String event) {
        this.home = home;
        this.outside = outside;
        this.state = state;
        this.event = event;
    }


    public String getHome() {
        return home;
    }
    public void setHome(String home) {
        this.home = new String(home);
    }
    public String getOutside() {
        return outside;
    }
    public void setOutside(String outside) {
        this.outside = outside;
    }
    public int getState() {
        return state;
    }
    public void setState(int state) {
        this.state = state;
    }
    public String getEvent() {
        return event;
    }
    public void setEvent(String event) {
        this.event = event;
    }


    @Override
    public String toString() {
        return "Futebol [home=" + home + ", outside=" + outside + ", state=" + state + ", event=" + event + "]";
    }


}