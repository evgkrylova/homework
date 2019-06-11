package g144.krylova.toDescribe;

import g144.krylova.toDescribe.DifficultClassInterface;
import g144.krylova.toDescribe.SimpleClass;

public class DifficultClass<Type> implements DifficultClassInterface {

    public DifficultClass(int value) { }

    private void method (Type argument)  { }

    public class SimpleClassInside extends Object {
        public int value;

        public SimpleClassInside(SimpleClass argument) { }
    }
}
