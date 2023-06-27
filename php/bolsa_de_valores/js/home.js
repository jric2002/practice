const PROTOCOL = window.location.protocol;
const HOSTNAME = window.location.hostname;
const PORT = (window.location.port == '') ? window.location.port : ":" + window.location.port;
const URL = PROTOCOL + "//" + HOSTNAME + PORT;