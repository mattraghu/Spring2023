import LandingPage from "./pages/Landing/Landing";
import AboutUsPage from "./pages/AboutUs";
import NavBar from "./components/NavBar";
// import Layout from "./layout/Layout";

import { Route, Routes } from "react-router-dom";

import { useEffect } from "react";

const sections = [
	{ text: "Home", url: "/", page: LandingPage },
	{ text: "About Us", url: "/About", page: AboutUsPage },
	// { text: "Services", url: "#" },
	// { text: "Contact", url: "#" },
];
function App() {
	useEffect(() => {
		// Redirect the user after the component mounts
		window.location.href =
			"https://sites.google.com/stevens.edu/design6project/home";
	}, []);

	return (
		<section className="bg-slate-700 min-h-screen min-w-full">
			<NavBar sections={sections} />
			<Routes>
				{sections.map((section) => {
					return <Route path={section.url} element={<section.page />} />;
				})}
			</Routes>
		</section>
	);
}

export default App;
