public class Exercise4 {
    public interface graph {
        void draw();
    }

    public class polygon implements graph {
        private double perimeter, area;

        @Override
        public void draw() {
        }
    }

    public class triangle extends polygon {
        public double side1, side2, side3;

        public void draw() {
        }
    }

    public class rectangle extends polygon {
        public double side1, side2, side3, side4;

        public void draw() {
        }
    }
}