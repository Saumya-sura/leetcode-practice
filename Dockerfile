FROM python:3.10

# Set working directory inside the container
WORKDIR /app

# Copy your project files
COPY . .

# Install Flask
RUN pip install flask

# Expose port 8000 so you can access it
EXPOSE 8000

# Run your app
CMD ["python", "main.py"]
