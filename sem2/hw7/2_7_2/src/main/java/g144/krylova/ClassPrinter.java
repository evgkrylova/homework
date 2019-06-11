package g144.krylova;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.lang.reflect.*;
import java.util.Arrays;

/**
 * Class containing methods to describe unknown class using the reflection.
 */
public class ClassPrinter {

    /**
     * Method printing the all possible information about class to the file.
     * @param someClass is class to describe.
     * @return string form of it.
     */
    public String printStructure(Class someClass) throws IOException {
        String fullName = "src\\main\\java\\g144\\krylova\\describedClasses\\" + someClass.getSimpleName() + ".java";
        File file = new File(fullName);
        FileWriter fileWriter = new FileWriter(file);

        StringBuffer builder = new StringBuffer();
        builder.append("package g144.krylova.describedClasses;\n\n");
        getStructure(someClass, builder);

        fileWriter.write(builder.toString());
        fileWriter.close();
        return builder.toString();
    }

    /**
     * Method fulling the information about the class structure.
     * @param builder is already existing part of the description.
     * @param someClass is class to describe.
     */
    private void getStructure(Class someClass, StringBuffer builder) {
        addClassName(someClass, builder);
        addSuperclass(someClass, builder);
        addInterfaces(someClass, builder);
        builder.append("{\n\t");
        addFields(someClass, builder);
        addConstructors(someClass, builder);
        addMethods(someClass, builder);
        addDeclaredClasses(someClass, builder);
        builder.append("\n}\n\n\t");
    }

    /**
     * Method adding information about the class declaration.
     * @param someClass is class to describe.
     * @param builder is already existing part of the description.
     */
    private void addClassName(Class someClass, StringBuffer builder) {
        if (someClass.getModifiers() != 0) {
            builder.append(Modifier.toString(someClass.getModifiers()) + " ");
        }

        builder.append("class ");
        getClassNameWithParameters(someClass, builder);
        builder.append(" ");
    }

    /**
     * Method adding information about the superclasses of the class.
     * @param someClass is class to describe.
     * @param builder is already existing part of the description.
     */
    private void addSuperclass(Class someClass, StringBuffer builder) {
        if (someClass.getSuperclass() != null) {
            builder.append("extends ");
            getClassNameWithParameters(someClass.getSuperclass(), builder);
            builder.append(" ");
        }
    }

    /**
     * Method adding information about the interfaces of the class.
     * @param someClass is class to describe.
     * @param builder is already existing part of the description.
     */
    private void addInterfaces(Class someClass, StringBuffer builder) {
        if (someClass.getInterfaces().length != 0) {
            builder.append("implements ");
            Class[] interfaces = someClass.getInterfaces();

            for (int i = 0; i < interfaces.length; i++) {
                builder.append(interfaces[i].getSimpleName());
                if (someClass.getTypeParameters().length != 0) {
                    TypeVariable[] parameters = interfaces[i].getTypeParameters();
                    builder.append("<");
                    for (int j = 0; j < parameters.length; j++) {
                        builder.append(parameters[j].getName());
                        if (j <= parameters.length - 2) {
                            builder.append(", ");
                        }
                    }
                    builder.append("> ");
                }
                if (i <= interfaces.length - 2) {
                    builder.append(", ");
                }
            }
        }
        builder.append(" ");
    }

    /**
     * Method adding information about the fields of the class.
     * @param someClass is class to describe.
     * @param builder is already existing part of the description.
     */
    private void addFields(Class someClass, StringBuffer builder) {
        if (someClass.getDeclaredFields().length != 0) {
            Field[] fields = someClass.getDeclaredFields();
            for (Field field : fields) {
                getField(builder, field);
                builder.append("\n\t");
            }
        }
    }

    /**
     * Method adding the only field.
     * @param builder is already existing part of the description.
     * @param field is field to describe.
     */
    private void getField(StringBuffer builder, Field field) {
        if (field.getModifiers() != 0) {
            builder.append(Modifier.toString(field.getModifiers()));
            builder.append(" ");
        }
        builder.append(field.getType().getSimpleName()).append(" ")
                .append(field.getName()).append(" = ");
        addType(builder, field.getType());
        builder.append("\n");
    }

    /**
     * Method adding information about the constructors of the class.
     * @param someClass is class to describe.
     * @param builder is already existing part of the description.
     */
    private void addConstructors(Class someClass, StringBuffer builder) {
        builder.append("\n\t");
        if (someClass.getDeclaredConstructors().length != 0) {
            Constructor[] constructors = someClass.getDeclaredConstructors();
            for (Constructor constructor : constructors) {
                if (constructor.getModifiers() != 0) {
                    builder.append(Modifier.toString(constructor.getModifiers())).append(" ");
                }
                builder.append(someClass.getSimpleName()).append("(");
                Parameter[] parameters = constructor.getParameters();
                for (int j = 0; j <= parameters.length - 1; j++) {
                    builder.append(parameters[j].getType().getSimpleName() + " " + parameters[j].getName());
                    if (j != parameters.length - 1) {
                        builder.append(", ");
                    }
                }
                builder.append(") { }\n\n\t");
            }
        }
    }

    /**
     * Method adding information about the methods of the class.
     * @param someClass is class to describe.
     * @param builder is already existing part of the description.
     */
    private void addMethods(Class someClass, StringBuffer builder) {
        if (someClass.getDeclaredMethods().length != 0) {
            Method[] methods = someClass.getDeclaredMethods();
            for (int i = 0; i < methods.length; i++) {
                getMethod(methods[i], builder);
                if (i != methods.length - 1) {
                    builder.append("\n\n\t");
                }
            }
        }
    }

    /**
     * Method adding the only method.
     * @param method is field to describe.
     * @param builder is already existing part of the description.
     */
    private void getMethod(Method method, StringBuffer builder) {
        if (method.getModifiers() != 0) {
            builder.append(Modifier.toString(method.getModifiers()))
                    .append(" ");
        }

        builder.append(method.getReturnType().getSimpleName()).append(" ")
                .append(method.getName()).append(" (");
        Parameter[] parameters = method.getParameters();
        getParameters(parameters, builder);
        builder.append(") ");
        getExceptions(method, builder);

        builder.append("{");
        if (!method.getReturnType().getSimpleName().equals("void")) {
            builder.append("\n\t\treturn ");
            addType(builder, method.getReturnType());
            builder.append("\n\t");
        } else {
            builder.append(" ");
        }

        builder.append("}");
    }

    /**
     * Method adding information about the declared classes in the class.
     * @param someClass is class to describe.
     * @param builder is already existing part of the description.
     */
    private void addDeclaredClasses(Class someClass, StringBuffer builder) {
        if (someClass.getDeclaredClasses().length != 0) {
            builder.append("\n\t");
            Class<?>[] classes = someClass.getDeclaredClasses();
            for (int i = 0; i < classes.length; i++) {
                getStructure(classes[i], builder);
                if (i < classes.length -1) {
                    builder.append("\n\n\t");
                }
            }
        }
    }

    /**
     * Method adding information about the parameters of the class.
     * @param parameters is the array of the parameters.
     * @param builder is already existing part of the description.
     */
    private void getParameters(Parameter[] parameters, StringBuffer builder) {
        for (int i = 0; i < parameters.length; i++) {
            builder.append(parameters[i].getParameterizedType().getTypeName()).append(" ")
                    .append(parameters[i].getName());
            if (i != parameters.length - 1) {
                builder.append(", ");
            }
        }
    }

    /**
     * Method adding information about the exceptions of the method.
     * @param method is method to describe.
     * @param builder is already existing part of the description.
     */
    private void getExceptions(Method method, StringBuffer builder) {
        if (method.getExceptionTypes().length > 0) {
            builder.append("throws ");
            Class[] exceptions = method.getExceptionTypes();
            for (int i = 0; i < exceptions.length; i++) {
                builder.append(exceptions[i].getName());
                if (i < exceptions.length - 1) {
                    builder.append(", ");
                }
            }
        }
        builder.append(" ");
    }

    /**
     * Method adding information about the name and parameters of the class.
     * @param someClass is class to describe.
     * @param builder is already existing part of the description.
     */
    private void getClassNameWithParameters(Class someClass, StringBuffer builder) {
        builder.append(someClass.getSimpleName());
        if (someClass.getTypeParameters().length > 0) {
            TypeVariable[] parameters = someClass.getTypeParameters();
            builder.append("<");
            int parametersLength = parameters.length;
            for (int i = 0; i < parametersLength; i++) {
                builder.append(parameters[i].getName());

                if (i < parametersLength - 1) {
                    builder.append(", ");
                }
            }
            builder.append(">");
        }
    }

    /**
     * AMethod adding information about the type.
     * @param builder is already existing part of the description.
     * @param type is type to describe.
     */
    private void addType(StringBuffer builder, Type type) {
        switch (type.getTypeName()) {
            case "boolean":
                builder.append("true;");
                break;
            case "Boolean":
                builder.append("true;");
                break;
            case "int":
                builder.append("0;");
                break;
            case "Integer":
                builder.append("Integer.valueOf(0);");
                break;
            case "double":
                builder.append("0.0;");
                break;
            case "Double":
                builder.append("Double.valueOf(0.0);");
                break;
            case "float":
                builder.append("0;");
                break;
            case "Float":
                builder.append("Float.valueOf(0);");
                break;
            case "byte":
                builder.append("0;");
                break;
            case "Byte":
                builder.append("Byte.valueOf(0);");
                break;
            case "String":
                builder.append("String.valueOf(\"\");");
                break;
            case "char":
                builder.append("'x';");
                break;
            case "Character":
                builder.append("Character.valueOf('x');");
                break;
            case "Long":
                builder.append("Long.valueOf(0);");
                break;
            case "Short":
                builder.append("Short.valueOf(0);");
                break;
            case "long":
                builder.append("0;");
                break;
            case "short":
                builder.append("0;");
                break;
            case "void":
                builder.append(";");
                break;
            default:
                builder.append("null;");
                break;
        }
    }

    /**
     * Method comparing two classes and printing the differences between them.
     * @param firstClass is the first class to compare.
     * @param secondClass is the second class to compare.
     * @return true if classes are equal and false otherwise.
     */
    public boolean diffClasses(Class firstClass, Class secondClass) {
        StringBuffer differences = new StringBuffer();
        getDifference(firstClass, secondClass, differences);

        if (differences.length() == 0) {
            System.out.println("Classes are equal.");
            return true;
        }
        System.out.println(differences);
        return false;
    }

    /**
     * Method fulling the information about the class structure.
     * @param firstClass is the first class to compare.
     * @param secondClass is the second class to compare.
     * @param differences builder is already existing part of the comparing.
     */
    private void getDifference(Class firstClass, Class secondClass, StringBuffer differences) {
        addFieldsDiff(firstClass, secondClass, differences);
        addMethodsDiff(firstClass, secondClass, differences);
        addDeclaredClassesDiff(firstClass, secondClass, differences);
    }

    /**
     * Method adding information about the fields comparing of the classes.
     * @param firstClass is the first class to compare.
     * @param secondClass is the second class to compare.
     * @param differences builder is already existing part of the comparing.
     */
    private void addFieldsDiff(Class firstClass, Class secondClass, StringBuffer differences) {
        Field[] firstFields = firstClass.getDeclaredFields();
        Field[] secondFields = secondClass.getDeclaredFields();
        if (Arrays.equals(firstFields, secondFields)) {
            return;
        }
        for (Field i : firstFields) {
            if (!containsField(secondClass, i)) {
                getField(differences, i);
            }
        }
        for (Field i : firstFields) {
            if (!containsField(firstClass, i)) {
                getField(differences, i);
            }
        }
    }

    /**
     * Method checking if the class containing the field.
     * @param someClass is class to check.
     * @param field is field to check.
     * @return true if the class contains the field and false otherwise
     */
    private boolean containsField(Class someClass, Field field) {
        if (Modifier.isFinal(field.getModifiers()) && field.getName().equals("this$0$")) {
            return true;
        }
        Field[] fields = someClass.getDeclaredFields();
        StringBuffer fieldString = new StringBuffer();
        getField(fieldString, field);
        for (Field i : fields) {
            StringBuffer current = new StringBuffer();
            getField(current, i);
            if (fieldString.toString().equals(current.toString())) {
                return true;
            }
        }
        return false;
    }

    /**
     * Method adding information about the methods comparing of the classes.
     * @param firstClass is the first class to compare.
     * @param secondClass is the second class to compare.
     * @param differences builder is already existing part of the comparing.
     */
    private void addMethodsDiff(Class firstClass, Class secondClass, StringBuffer differences) {
        Method[] methodsFirst = firstClass.getDeclaredMethods();
        Method[] methodsSecond = secondClass.getDeclaredMethods();
        if (Arrays.equals(methodsFirst, methodsSecond)) {
            return;
        }
        for (Method i : methodsFirst) {
            if (!containsMethod(secondClass, i)) {
                getMethod(i, differences);
                differences.append("\n");
            }
        }
        for (Method i : methodsSecond) {
            if (!containsMethod(firstClass, i)) {
                getMethod(i, differences);
                differences.append("\n");
            }
        }
    }

    /**
     * Method checking if the class containing the method.
     * @param someClass is class to check.
     * @param method is method to check.
     * @return true if the class contains the method and false otherwise
     */
    private boolean containsMethod(Class someClass, Method method) {
        Method[] methods = someClass.getDeclaredMethods();
        StringBuffer methodString = new StringBuffer();
        getMethod(method, methodString);
        for (Method i : methods) {
            StringBuffer current = new StringBuffer();
            getMethod(i, current);
            if (current.toString().equals(methodString.toString())) {
                return true;
            }
        }
        return false;
    }

    /**
     * Method adding information about the comparing of declared classes.
     * @param firstClass is the first class to compare.
     * @param secondClass is the second class to compare.
     * @param differences builder is already existing part of the comparing.
     */
    private void addDeclaredClassesDiff(Class firstClass, Class secondClass, StringBuffer differences) {
        Class[] firstClasses = firstClass.getDeclaredClasses();
        Class[] secondClasses = secondClass.getDeclaredClasses();
        if (firstClasses.length > 0 && secondClasses.length > 0) {
            if (Arrays.equals(firstClasses, secondClasses)) {
                return;
            }
            for (Class currentFirst : firstClasses) {
                for (Class currentSecond : secondClasses) {
                    getDifference(currentFirst, currentSecond, differences);
                }
            }
        } else if (firstClasses.length > 0) {
            for (Class current : firstClasses) {
                getStructure(current, differences);
            }
        } else if (secondClasses.length > 0) {
            for (Class current : secondClasses) {
                getStructure(current, differences);
            }
        }
    }
}
