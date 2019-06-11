package g144.krylova;

import org.junit.jupiter.api.Test;

import java.io.IOException;
import java.net.URL;
import java.net.URLClassLoader;

import static org.junit.jupiter.api.Assertions.*;

class ClassPrinterTest {

    @Test
    void simplePrintStructureTest() throws IOException, ClassNotFoundException {
        ClassPrinter printer = new ClassPrinter();
        ClassLoader loader = new URLClassLoader(new URL[]{new URL("file://")});
        Class<?> printedClass = loader.loadClass("g144.krylova.toDescribe.SimpleClass");
        String result = printer.printStructure(printedClass);
        String expected = "package g144.krylova.describedClasses;\n" +
                "\n" +
                "public class SimpleClass extends Object  {\n" +
                "\tprivate int value = 0;\n" +
                "\n" +
                "\t\n" +
                "\tpublic SimpleClass() { }\n" +
                "\n" +
                "\tprivate void setValue ()  { }\n" +
                "\n" +
                "\tprivate String valueToString ()  {\n" +
                "\t\treturn null;\n" +
                "\t}\n" +
                "}\n" +
                "\n" +
                "\t";

        assertEquals(expected, result);
    }

    @Test
    void difficultPrintStructureTest() throws IOException, ClassNotFoundException {
        ClassPrinter printer = new ClassPrinter();
        ClassLoader loader = new URLClassLoader(new URL[]{new URL("file://")});
        Class<?> printedClass = loader.loadClass("g144.krylova.toDescribe.DifficultClass");
        String result = printer.printStructure(printedClass);

        assertEquals("package g144.krylova.describedClasses;\n" +
                "\n" +
                "public class DifficultClass<Type> extends Object implements DifficultClassInterface<Type>  {\n" +
                "\t\n" +
                "\tpublic DifficultClass(int arg0) { }\n" +
                "\n" +
                "\tprivate void method (Type arg0)  { }\n" +
                "\tpublic class SimpleClassInside extends Object  {\n" +
                "\tpublic int value = 0;\n" +
                "\n" +
                "\tfinal DifficultClass this$0 = null;\n" +
                "\n" +
                "\t\n" +
                "\tpublic SimpleClassInside(DifficultClass arg0, SimpleClass arg1) { }\n" +
                "\n" +
                "\t\n" +
                "}\n" +
                "\n" +
                "\t\n" +
                "}\n" +
                "\n" +
                "\t", result);
    }

    @Test
    void simpleDiffClasses() throws IOException, ClassNotFoundException{
        ClassPrinter printer = new ClassPrinter();
        ClassLoader loader = new URLClassLoader(new URL[]{new URL("file://")});
        Class printedClass = loader.loadClass("g144.krylova.describedClasses.SimpleClass");
        printer.printStructure(printedClass);

        ClassLoader loaderOriginal = new URLClassLoader(new URL[]{new URL("file://")});
        Class originalClass = loaderOriginal.loadClass("g144.krylova.toDescribe.SimpleClass");
        assertTrue(printer.diffClasses(printedClass, originalClass));
    }

    @Test
    void difficultDiffClasses() throws IOException, ClassNotFoundException{
        ClassPrinter printer = new ClassPrinter();
        ClassLoader loader = new URLClassLoader(new URL[]{new URL("file://")});
        Class printedClass = loader.loadClass("g144.krylova.describedClasses.DifficultClass");
        printer.printStructure(printedClass);

        ClassLoader loaderOriginal = new URLClassLoader(new URL[]{new URL("file://")});
        Class originalClass = loaderOriginal.loadClass("g144.krylova.toDescribe.DifficultClass");
        boolean result = printer.diffClasses(printedClass, originalClass);
        assertTrue(result);
    }
}