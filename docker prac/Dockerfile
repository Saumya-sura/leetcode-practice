FROM python:3.11-slim

WORKDIR /app

# 1. Create a non-root system user named 'appuser'
RUN useradd -m appuser

COPY requirements.txt .

RUN pip install --no-cache-dir -r requirements.txt

# 2. Switch from root to the new user
USER appuser

# 3. Copy the application code and grant ownership to 'appuser'
COPY --chown=appuser:appuser app.py .

EXPOSE 8080

CMD ["python", "app.py"]