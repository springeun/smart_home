const { initializeApp } = require ("firebase/app");
const { getAuth } = require("firebase/auth");

const firebaseConfig = {
 --
};


// Initialize Firebase
const app = initializeApp(firebaseConfig);
const auth = getAuth(app);

module.exports = auth;
