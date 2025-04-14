// import p5 from 'p5/lib/p5'

import p5 from 'p5'
import { GiftWrapping } from './giftWrapping'

const sketch = window
const giftWrappingCanvas = document.getElementById("giftWrappingCanvas")

const giftWrapping = new GiftWrapping(50, 100)

// Create a new p5 instance, passing the canvas element
sketch.setup = () => {
  createCanvas(800, 600, P2D, giftWrappingCanvas)
  giftWrapping.setupPoints()
}

sketch.draw = () => {
  background(0)

  giftWrapping.draw()
  giftWrapping.step()
}

