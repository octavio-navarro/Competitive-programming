// import p5 from 'p5/lib/p5'

import p5 from 'p5'
import GUI from 'lil-gui'
import { GiftWrapping } from './giftWrapping'
import { GrahamScan } from './grahamScan'

// const sketch = window

let giftWrappingP5 = undefined
let grahamScanP5 = undefined

const gui = new GUI()
const config = {
  maxPoints: 50,
  pointsBuffer: 100,
  seed: 42,
  frameRate: 10,
  restart: false,
  reset: function(){ 
    giftWrappingP5.remove()
    grahamScanP5.remove()

    let gwCanvas = document.createElement("canvas")
    gwCanvas.id = "giftWrappingCanvas"
    document.getElementById("giftWrappingContainer").append(gwCanvas)
    
    let gsCanvas = document.createElement("canvas")
    gsCanvas.id = "grahamScanCanvas" 
    document.getElementById("grahamScanContainer").appendChild(gsCanvas)

    main()
  }
}

gui.add(config, "maxPoints", 50, 100)
gui.add(config, "pointsBuffer", 50, 200)
gui.add(config, "seed", 0, 100)
gui.add(config, "frameRate", 10, 60)
gui.add(config, "reset")

gui.close()

function main(){

  giftWrappingP5 = new p5((p)=> {

    const giftWrapping = new GiftWrapping(p, config["maxPoints"], config["pointsBuffer"], config["seed"])
    const giftWrappingCanvas = document.getElementById("giftWrappingCanvas")

    p.setup = () => {
      p.createCanvas(800, 600, p.P2D, giftWrappingCanvas)
      giftWrapping.setupPoints()
    }

    p.draw = () => {
      p.frameRate(config["frameRate"])
      p.background(0)

      giftWrapping.draw()
      giftWrapping.step()
    }
  })

  grahamScanP5 = new p5((p)=> {

    const grahamScan = new GrahamScan(p, config["maxPoints"], config["pointsBuffer"], config["seed"])
    const grahamScanCanvas = document.getElementById("grahamScanCanvas")

    p.setup = () => {
      p.createCanvas(800, 600, p.P2D, grahamScanCanvas)
      grahamScan.setupPoints()
    }

    p.draw = () => {
      p.frameRate(config["frameRate"])
      p.background(0)

      grahamScan.draw()
      grahamScan.step()
    }
  })

  console.log(grahamScanP5)

}

main()
