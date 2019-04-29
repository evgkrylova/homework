package g144.krylova;

import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.fxml.FXML;
import javafx.scene.control.*;

public class Controller {

    @FXML
    Slider slider = new Slider();

    @FXML
    ProgressBar progressBar = new ProgressBar();

    /**
     * Method changing the bar according to the slider value.
     */
    public void initialize() {
        slider.valueProperty().addListener((observable, oldValue, newValue) -> progressBar.progressProperty().setValue(newValue));
    }
}
