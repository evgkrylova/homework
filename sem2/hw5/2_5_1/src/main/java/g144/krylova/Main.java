package g144.krylova;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root = FXMLLoader.load(getClass().getResource("sliderAndBar.fxml"));
        primaryStage.setTitle("Slider and progress bar");
        primaryStage.setScene(new Scene(root, 300, 100));
        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}
