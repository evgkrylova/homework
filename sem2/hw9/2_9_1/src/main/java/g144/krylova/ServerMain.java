package g144.krylova;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class ServerMain extends Application {
    private ServerController controller;

    @Override
    public void start(Stage primaryStage) throws Exception {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("tictactoe_server.fxml"));
        Parent root = loader.load();
        controller = loader.getController();

        primaryStage.setTitle("tic-tac-toe (x-player)");
        primaryStage.setScene(new Scene(root, 300, 400));
        primaryStage.setMinHeight(450);
        primaryStage.setMinWidth(330);
        primaryStage.show();
    }

    @Override
    public void stop() {
        if (controller.progressStatus()) {
            controller.reactToExit();
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