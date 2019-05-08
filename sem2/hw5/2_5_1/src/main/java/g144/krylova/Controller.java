package g144.krylova;

import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.fxml.FXML;
import javafx.scene.control.*;

public class Controller {

    /** create slider */
    @FXML
    Slider slider = new Slider();

    /** created progressBar */
    @FXML
    ProgressBar progressBar = new ProgressBar();

    /**
     * initialize method
     *
     * progress bar change, when slider value change
     */
    public void initialize() {
        slider.valueProperty().addListener(new ChangeListener<Number>() {
            @Override
            public void changed(ObservableValue<? extends Number> observable, Number oldValue, Number newValue) {
                progressBar.setProgress(newValue.doubleValue());
            }
        });
    }
}
