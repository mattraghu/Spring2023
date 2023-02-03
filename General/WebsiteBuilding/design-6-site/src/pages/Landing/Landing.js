function LandingPage() {
	return (
		<div className="landing flex flex-col justify-between h-full">
			<div className="py-10 px-10 text-center min-w-full">
				<h1 className="text-5xl py-2 font-extrabold">
					Welcome to our website!
				</h1>
				<p className="text-2xl py-2">
					We are a group of students from Stevens Institute of Technology who
					are taking Design 6.
				</p>
			</div>

			<div className="flex items-center flex-col">
				{/* Hello */}
				<img
					src="https://cdn.discordapp.com/attachments/1018300243512664155/1070958477406654514/Mountains-transformed.png"
					className="scaletofit h-300 w-full"
				/>
			</div>
		</div>
	);
}

export default LandingPage;
