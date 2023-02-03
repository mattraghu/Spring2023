// Create a nav bar based on an items list

function NavBar(props) {
	// Create a nav bar based on an items list
	// props = {items: items}
	// items = [{link: link, text: text}, ...]
	function NavBarElement(section) {
		// Create a nav bar element for the item
		// item = {link: link, text: text}
		return (
			<button className="bg-gray-900 px-2 py-1 rounded">{section.text}</button>
		);
	}
	return (
		<div className="px-10 py-5 flex justify-between">
			{/* Website Logo */}
			<div className="flex gap-3 items-center">
				{/* Add Website Logo */}
				<img
					src="https://media.discordapp.net/attachments/1018300243512664155/1070941945498697728/download.jpg"
					alt="Logo"
					className="w-14 h-14 rounded-tl-3xl rounded-br-3xl"
				/>

				{/* Add Website Name */}
				<span className="text-2xl font-bold">Design 6 Project</span>
			</div>
			<div className="flex gap-3 items-center">
				{props.sections.map((item) => {
					return NavBarElement(item);
				})}
			</div>
		</div>
	);
}

export default NavBar;
