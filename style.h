const char css[] PROGMEM = R"=====(
body { 
  font-family: Helvetica Neue;
  background-color: black;
  color: white;
}
h2 {
  text-transform: uppercase;
  width: 100%;
}
hr {
  width: 100%;
  border: 1px solid #323136;
  margin-top: 1.5rem;
}
.container {
  display: flex;
  flex-wrap: wrap;
  width: 95%;
  max-width: 1000px;
  margin: 0 auto;
  justify-content: space-between;
}
.container button {
  -webkit-apperance: unset;
  touch-action: manipulation;
  width: 8rem;
  height: 2rem;
  border-radius: 16px;
  border: unset;
  background-color: white;
  color: black;
  font-weight: 600;
  margin: 0.3rem 0;
  padding: 0.9rem;
  font-size: 1.2rem;
  line-height: 1.2rem;
  box-sizing: unset;

  @media (min-width: 768px) {
    margin: 0.3rem;
  }
}
.container button i::before {
  content: '';
}
)=====";