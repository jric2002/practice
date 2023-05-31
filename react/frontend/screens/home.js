import React from "react";
import { View, Text, StyleSheet, FlatList, TouchableOpacity } from "react-native";
import { NavigationContainer } from "@react-navigation/native";
import { createNativeStackNavigator } from "@react-navigation/native-stack";
import db_tasks from "./../tasks/tasks.json";

const styles = StyleSheet.create({
    home: {
        flex: 1,
        backgroundColor: "#98ca3f",
        paddingVertical: 16
    },
    createTaskButton: {
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
    },
    task: {
        backgroundColor: "rgba(0, 0, 0, 0.75)",
        borderWidth: 1,
        borderColor: "#ffffff",
        borderRadius: 10,
        padding: 16,
        marginHorizontal: 32,
        marginVertical: 16
    },
    title: {
        fontSize: 20,
        color: "#ffffff",
    },
    description: {
        fontSize: 16,
        color: "#ffffff",
        marginVertical: 8
    },
    deleteButton: {
        backgroundColor: "#f00",
        borderRadius: 10,
        padding: 8,
        marginTop: 16
    }
});

const tasks = db_tasks;
const Home = ({navigation}) => {
    const deleteTask = (id) => {
        const size = tasks.length - id;
        tasks.splice((id - 1), 1);
        for (var i = 0; i < size; i++) {
            tasks[id - 1]["id"] = id;
            id += 1;
        }
    }
    return (
        <View style={styles.home}>
            <TouchableOpacity
                style={styles.createTaskButton}
                onPress={() => navigation.navigate("Add_task")}
            >
                <Text style={styles.buttonText}>Crear nueva tarea</Text>
            </TouchableOpacity>
            <FlatList
                data={tasks}
                keyExtractor={item => item.id.toString()}
                renderItem={({item}) => {
                    return (
                        <View style={styles.task}>
                            <View>
                                <Text style={styles.title}>{item.title}</Text>
                                <Text style={styles.description}>{item.description}</Text>
                            </View>
                            <TouchableOpacity
                                style={styles.deleteButton}
                                onPress={() => deleteTask(parseInt(item.id))}
                            >
                                <Text style={styles.buttonText}>Eliminar</Text>
                            </TouchableOpacity>
                        </View>
                    );
                }}
            />
        </View>
    );
};


export default Home;