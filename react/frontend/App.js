import React from "react";
import { Text, StatusBar, TouchableOpacity } from "react-native";
import { NavigationContainer } from "@react-navigation/native";
import { createNativeStackNavigator } from "@react-navigation/native-stack";

/* Author: José Rodolfo */
import Home from "./screens/home.js";
import AddTask from "./screens/add_task.js";

const Stack = createNativeStackNavigator();
const App = () => {
  return (
    <NavigationContainer>
      <StatusBar ></StatusBar>
      <Stack.Navigator>
        <Stack.Screen
          name="Home"
          component={Home}
          options={() => ({
            title: "Tareas",
            headerStyle: {
              backgroundColor: "#0a0a0a"
            },
            headerTitleStyle: {
              color: "#ffffff"
            }
          })}/>
        <Stack.Screen
          name="Add_task"
          component={AddTask}
          options={() => ({
            title: "Agregar tarea",
            headerStyle: {
              backgroundColor: "#0a0a0a"
            },
            headerTitleStyle: {
              color: "#ffffff"
            }
          })}
        />
      </Stack.Navigator>
    </NavigationContainer>
  );
};
export default App;