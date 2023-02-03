import LandingPage from "./pages/Landing/Landing";
import NavBar from "./components/NavBar";
// import Layout from "./layout/Layout";

const sections = [
	{ text: "Home", url: "#" },
	{ text: "About", url: "#" },
	{ text: "Services", url: "#" },
	{ text: "Contact", url: "#" },
];
function App() {
	return (
		<main>
			<section className="bg-slate-700 min-h-screen min-w-full">
				<NavBar sections={sections} />
				<LandingPage />
			</section>
		</main>
	);
}

export default App;
