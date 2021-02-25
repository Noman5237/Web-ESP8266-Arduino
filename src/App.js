import ContinuousSlider from "./components/customSlider.js";
import NativeSelects from "./components/customDropDown.js";

function App() {
  return (
    <div>
      <p>Hello World</p>
      <ContinuousSlider pin={10} />
      <ContinuousSlider pin={11} />
      <NativeSelects pin={12} />
      <br />
      <NativeSelects pin={13} />
    </div>
  );
}

export default App;
