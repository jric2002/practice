const API = "http://192.168.43.138:3000/task";

const getTasks = async () => {
    const res = await fetch(URL);
    const data = await res.json();
    console.log(data);
};

export { getTasks };