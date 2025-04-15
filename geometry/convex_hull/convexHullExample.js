// import p5 from 'p5/lib/p5'

import p5 from 'p5'
import { GiftWrapping } from './giftWrapping'
import { GrahamScan } from './grahamScan'

// const sketch = window
const giftWrappingCanvas = document.getElementById("giftWrappingCanvas")
const grahamScanCanvas = document.getElementById("grahamScanCanvas")

const points = []
const maxPoints = 50
const pointsBuffer = 100
const seed = 42
const frameRate = 10

const giftWrappingP5 = new p5((p)=> {

  const giftWrapping = new GiftWrapping(p, maxPoints, pointsBuffer, seed)
  
  p.setup = () => {
    p.createCanvas(800, 600, p.P2D, giftWrappingCanvas)
    giftWrapping.setupPoints()
    p.frameRate(frameRate)
  }

  p.draw = () => {
    p.background(0)

    giftWrapping.draw()
    giftWrapping.step()
  }
})

const grahamScanP5 = new p5((p)=> {

  const grahamScan = new GrahamScan(p, maxPoints, pointsBuffer, seed)
  
  p.setup = () => {
    p.createCanvas(800, 600, p.P2D, grahamScanCanvas)
    grahamScan.setupPoints()
    p.frameRate(frameRate)
  }

  p.draw = () => {
    p.background(0)

    grahamScan.draw()
    grahamScan.step()
  }
})
