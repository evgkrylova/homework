package g144.krylova;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import java.io.IOException;

public class ServerMain extends Application {
    private ServerController controller;
    @Override
    public void start(Stage primaryStage) throws Exception {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("tictactoe_server.fxml"));
            Parent root = loader.load();
            controller = loader.getController();
            primaryStage.setTitle("tic-tac-toe (x-player)");
            primaryStage.setScene(new Scene(root, 600, 600));
            primaryStage.setMinHeight(350);
            primaryStage.setMinWidth(350);
            primaryStage.setResizable(true);
            primaryStage.show();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void stop() {
        if (controller.isExited()) {
            controller.sendExitMessage();
        } else {
            controller.closeConnection();
        }
        try {
            super.stop();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        launch(args);
    }
}