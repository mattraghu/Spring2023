function Layout(props) {
	return (
		<div className="mainlayout">
			<main className="main">{props.children}</main>
		</div>
	);
}

export default Layout;
