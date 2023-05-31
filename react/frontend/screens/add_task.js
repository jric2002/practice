import React from "react";
import { View, Text, StyleSheet, TextInput, TouchableOpacity, Touchable } from "react-native";
import { NavigationContainer } from "@react-navigation/native";
import { createNativeStackNavigator } from "@react-navigation/native-stack";
import db_tasks from "./../tasks/tasks.json";

const styles = StyleSheet.create({
    addTask: {
        flex: 1,
        backgroundColor: "#121212",
        paddingVertical: 16
    },
    textInput: {
        color: "#ffffff",
        fontSize: 16,
        backgroundColor: "transparent",
        borderWidth: 1,
        borderColor: "#98ca3f",
        borderRadius: 10,
        paddingHorizontal: 16,
        paddingVertical: 8,
        marginHorizontal: 32,
        marginVertical: 16
    },
    saveButton: {
        backgroundColor: "#98ca3f",
        borderRadius: 10,
        padding: 8,
        marginHorizontal: 32,
        marginVertical: 16
    },
    buttonText: {
        color: "#ffffff",
        textAlign: "center",
        fontSize: 20
    }
});

const tasks = db_tasks;
const addTask = ({navigation}) => {
    const tempData = {
        id: (tasks.length + 1),
        title: "",
        description: ""
    };
    return (
        <View style={styles.addTask}>
            <TextInput
                style={styles.textInput}
                placeholder="Título"
                placeholderTextColor="rgba(255, 255, 255, 0.25)"
                onChangeText={text => tempData["title"] = text}
            ></TextInput>
            <TextInput
                style={styles.textInput}
                placeholder="Descripción"
                placeholderTextColor="rgba(255, 255, 255, 0.25)"
                onChangeText={text => tempData["description"] = text}
                multiline={true}
            ></TextInput>
            <TouchableOpacity
                style={styles.saveButton}
                onPress={() => {
                    tasks.push(tempData);
                    navigation.navigate("Home");
                }}
            >
                <Text style={styles.buttonText}>Agregar tarea</Text>
            </TouchableOpacity>
        </View>
    );
};
export default addTask;