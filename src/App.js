import ContinuousSlider from "./components/customSlider.js";
import NativeSelects from "./components/customDropDown.js";
require("dotenv").config();
const serverIP = process.env.REACT_APP_SERVER_IP;
function App() {
  return (
    <div>
      <p>PWM 10</p>
      <ContinuousSlider pin={10} />
      <p>PWM 11</p>
      <ContinuousSlider pin={11} />
      <NativeSelects pin={12} />
      <br />
      <NativeSelects pin={13} />
    </div>
  );
}
export { serverIP };
export default App;
