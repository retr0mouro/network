package pacote;

import java.time.LocalDate;

public class Youtube{
    private String name;
    private byte[] content;
    private LocalDate uploadDate;
    private int definition;
    private int duration;
    private String[] comment;
    private int likes;
    private int dislikes;

    


    public String getName() {
        return name;
    }




    public void setName(String name) {
        this.name = name;
    }




    public byte[] getContent() {
        return content;
    }




    public void setContent(byte[] content) {
        this.content = content;
    }




    public LocalDate getUploadDate() {
        return uploadDate;
    }




    public void setUploadDate(LocalDate uploadDate) {
        this.uploadDate = uploadDate;
    }




    public int getDefinition() {
        return definition;
    }




    public void setDefinition(int definition) {
        this.definition = definition;
    }




    public int getDuration() {
        return duration;
    }




    public void setDuration(int duration) {
        this.duration = duration;
    }




    public String[] getComment() {
        return comment;
    }




    public void setComment(String[] comment) {
        this.comment = comment;
    }




    public int getLikes() {
        return likes;
    }




    public void setLikes(int likes) {
        this.likes = likes;
    }




    public int getDislikes() {
        return dislikes;
    }




    public void setDislikes(int dislikes) {
        this.dislikes = dislikes;
    }




    public Youtube(String name, byte[] content, LocalDate uploadDate, int definition, int duration, String[] comment,
            int likes, int dislikes) {
        this.name = name;
        this.content = content;
        this.uploadDate = uploadDate;
        this.definition = definition;
        this.duration = duration;
        this.comment = comment;
        this.likes = likes;
        this.dislikes = dislikes;
    }


    public void insertComment(String comment){
        for(int i = 0;i < this.comment.length;i++){
            if(this.comment[i] == null){
                this.comment[i] = String.copyValueOf(comment.toCharArray());
                System.out.println("Comentário inserido!");
            }
        }
    }


}