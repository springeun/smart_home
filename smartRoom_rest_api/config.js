const { initializeApp } = require ("firebase/app");
const { getAuth } = require("firebase/auth");

const firebaseConfig = {
  apiKey: "AIzaSyCxl-0pbCJNOITw4IofyptWCpmbXVuZH5I",
  authDomain: "esp8266firebase-a017f.firebaseapp.com",
  databaseURL: "https://esp8266firebase-a017f-default-rtdb.asia-southeast1.firebasedatabase.app",
  projectId: "esp8266firebase-a017f",
  storageBucket: "esp8266firebase-a017f.appspot.com",
  messagingSenderId: "224421342334",
  appId: "1:224421342334:web:7399eab88905df8ca97c2f",
  measurementId: "G-BF3V0PYXCK"
};


// Initialize Firebase
const app = initializeApp(firebaseConfig);
const auth = getAuth(app);

module.exports = auth;