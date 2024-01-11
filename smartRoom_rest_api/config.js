const { initializeApp } = require ("firebase/app");
const { getAuth } = require("firebase/auth");

const firebaseConfig = {
 apiKey: "--",
 authDomain: "--",
 databaseURL: "--",
 projectId: "--",
 storageBucket: "-",
 messagingSenderId: "--",
 appId: "--",
 measurementId: "--"
};


// Initialize Firebase
const app = initializeApp(firebaseConfig);
const auth = getAuth(app);

module.exports = auth;
