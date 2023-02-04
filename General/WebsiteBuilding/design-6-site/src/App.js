import LandingPage from "./pages/Landing/Landing";
import AboutUsPage from "./pages/AboutUs";
import NavBar from "./components/NavBar";
// import Layout from "./layout/Layout";

import { Route, Routes } from "react-router-dom";

const sections = [
	{ text: "Home", url: "/", page: LandingPage },
	{ text: "About Us", url: "/About", page: AboutUsPage },
	// { text: "Services", url: "#" },
	// { text: "Contact", url: "#" },
];
function App() {
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
