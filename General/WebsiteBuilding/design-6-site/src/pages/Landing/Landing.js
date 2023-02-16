function LandingPage() {
	return (
		<div className="LandingPageMainContainer min-h-screen min-w-full">
			<div className="background flex flex-col justify-between h-full w-full">
				<div className="py-10 px-10 text-center min-w-full">
					<h1 className="text-5xl py-2 font-extrabold">
						We've Moved To A New Location! Click Here To Visit Our New Site!
					</h1>
					<a
						href="https://sites.google.com/stevens.edu/design6project/home"
						className="text-5xl py-2 font-extrabold text-blue-300"
					>
						New Site
					</a>
					{/* <h1 className="text-5xl py-2 font-extrabold">
						Welcome to our website!
					</h1> */}
					{/* <p className="text-2xl py-2">
						We are a group of students from Stevens Institute of Technology who
						are taking Design 6.
					</p> */}
				</div>

				<div className="flex items-center flex-col">
					<img
						src="https://cdn.discordapp.com/attachments/1018300243512664155/1070958477406654514/Mountains-transformed.png"
						className="scaletofit min-h-screen max-h-screen w-full"
					/>
				</div>
			</div>
		</div>
	);
}

export default LandingPage;
