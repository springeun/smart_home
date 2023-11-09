// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getAnalytics } from "firebase/analytics";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
  apiKey: "AIzaSyDw_UmDkpt0lsHG-YlyScB9rhOSs6zREPI",
  authDomain: "smartroom-cf86c.firebaseapp.com",
  databaseURL: "https://smartroom-cf86c-default-rtdb.asia-southeast1.firebasedatabase.app",
  projectId: "smartroom-cf86c",
  storageBucket: "smartroom-cf86c.appspot.com",
  messagingSenderId: "414072390733",
  appId: "1:414072390733:web:e6b3413cd9d5d79a95c804",
  measurementId: "G-GJE0E9XWMR"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const analytics = getAnalytics(app);